
#include "Interfaces/Car/Reporter/Reporter_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace Car {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Reporter_caller_stream::Reporter_caller_stream(Reporter &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Reporter_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool Reporter_caller_stream::call(std::string &name_function,
                                  CompoMe::Function_stream_recv &is,
                                  CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("send_err"):
    result = this->send_err(is, os);
    break;

  case str2int("send_info"):
    result = this->send_info(is, os);
    break;
  };

  return result;
}

bool Reporter_caller_stream::send_err(CompoMe::Function_stream_recv &is,
                                      CompoMe::Return_stream_send &os) {

  i32 l_err_code;
  is >> l_err_code;
  is.get();

  CompoMe::String l_message;
  is >> l_message;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.send_err(l_err_code, l_message);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Reporter_caller_stream::send_info(CompoMe::Function_stream_recv &is,
                                       CompoMe::Return_stream_send &os) {

  i32 l_info_code;
  is >> l_info_code;
  is.get();

  CompoMe::String l_message;
  is >> l_message;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.send_info(l_info_code, l_message);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace Car
