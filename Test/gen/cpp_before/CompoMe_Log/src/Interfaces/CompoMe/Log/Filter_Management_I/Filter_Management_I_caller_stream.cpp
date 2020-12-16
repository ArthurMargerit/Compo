
#include "Interfaces/CompoMe/Log/Filter_Management_I/Filter_Management_I_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace CompoMe {

namespace Log {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Filter_Management_I_caller_stream::Filter_Management_I_caller_stream(
    Filter_Management_I &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Filter_Management_I_caller_stream::call(CompoMe::Function_stream_recv &is,
                                             CompoMe::Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool Filter_Management_I_caller_stream::call(std::string &name_function,
                                             CompoMe::Function_stream_recv &is,
                                             CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("add"):
    result = this->add(is, os);
    break;

  case str2int("del"):
    result = this->del(is, os);
    break;
  };

  return result;
}

bool Filter_Management_I_caller_stream::add(CompoMe::Function_stream_recv &is,
                                            CompoMe::Return_stream_send &os) {

  CompoMe::Log::Kind_e l_k;
  is >> l_k;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.add(l_k);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Filter_Management_I_caller_stream::del(CompoMe::Function_stream_recv &is,
                                            CompoMe::Return_stream_send &os) {

  CompoMe::Log::Kind_e l_k;
  is >> l_k;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.del(l_k);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace Log

} // namespace CompoMe
