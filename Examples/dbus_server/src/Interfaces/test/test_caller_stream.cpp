
#include "Interfaces/test/test_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

test_caller_stream::test_caller_stream(test &pcomp)
    : test_p_caller_stream(pcomp), comp(pcomp) {
  return;
}

bool test_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool test_caller_stream::call(std::string &name_function,
                              CompoMe::Function_stream_recv &is,
                              CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("f7"):
    result = this->f7(is, os);
    break;

  case str2int("f8"):
    result = this->f8(is, os);
    break;

  case str2int("f9"):
    result = this->f9(is, os);
    break;

  case str2int("f10"):
    result = this->f10(is, os);
    break;

  case str2int("f11"):
    result = this->f11(is, os);
    break;

  case str2int("f12"):
    result = this->f12(is, os);
    break;

  case str2int("get_a"):
    result = this->get_a(is, os);
    break;

  case str2int("set_a"):
    result = this->set_a(is, os);
    break;

  case str2int("get_b"):
    result = this->get_b(is, os);
    break;

  case str2int("set_b"):
    result = this->set_b(is, os);
    break;

  default:
    return test_p_caller_stream::call(name_function, is, os);
    break;
  };

  return result;
}

bool test_caller_stream::f7(CompoMe::Function_stream_recv &is,
                            CompoMe::Return_stream_send &os) {

  ui8 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f7(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::f8(CompoMe::Function_stream_recv &is,
                            CompoMe::Return_stream_send &os) {

  ui16 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f8(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::f9(CompoMe::Function_stream_recv &is,
                            CompoMe::Return_stream_send &os) {

  ui32 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f9(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::f10(CompoMe::Function_stream_recv &is,
                             CompoMe::Return_stream_send &os) {

  ui64 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f10(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::f11(CompoMe::Function_stream_recv &is,
                             CompoMe::Return_stream_send &os) {

  S1 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f11(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::f12(CompoMe::Function_stream_recv &is,
                             CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.f12();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::get_a(CompoMe::Function_stream_recv &is,
                               CompoMe::Return_stream_send &os) {
  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {
    os << this->comp.get_a();
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::set_a(CompoMe::Function_stream_recv &is,
                               CompoMe::Return_stream_send &os) {
  i32 set_val;
  is >> set_val;

  char l = is.get();
  if (l != ')') {
    return false;
  }

  try {
    this->comp.set_a(set_val);
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::get_b(CompoMe::Function_stream_recv &is,
                               CompoMe::Return_stream_send &os) {
  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {
    os << this->comp.get_b();
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller_stream::set_b(CompoMe::Function_stream_recv &is,
                               CompoMe::Return_stream_send &os) {
  i64 set_val;
  is >> set_val;

  char l = is.get();
  if (l != ')') {
    return false;
  }

  try {
    this->comp.set_b(set_val);
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}
