
#include "Interfaces/Information/Information_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Information_caller_stream::Information_caller_stream(Information &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Information_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool Information_caller_stream::call(std::string &name_function,
                                     CompoMe::Function_stream_recv &is,
                                     CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("get_name"):
    result = this->get_name(is, os);
    break;

  case str2int("get_type"):
    result = this->get_type(is, os);
    break;

  case str2int("get_location"):
    result = this->get_location(is, os);
    break;
  };

  return result;
}

bool Information_caller_stream::get_name(CompoMe::Function_stream_recv &is,
                                         CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.get_name();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Information_caller_stream::get_type(CompoMe::Function_stream_recv &is,
                                         CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.get_type();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Information_caller_stream::get_location(CompoMe::Function_stream_recv &is,
                                             CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.get_location();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}
