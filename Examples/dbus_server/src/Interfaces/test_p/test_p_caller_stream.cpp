
#include "Interfaces/test_p/test_p_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

test_p_caller_stream::test_p_caller_stream(test_p &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool test_p_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool test_p_caller_stream::call(std::string &name_function,
                                CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("f0"):
    result = this->f0(is, os);
    break;

  case str2int("f1"):
    result = this->f1(is, os);
    break;

  case str2int("f2"):
    result = this->f2(is, os);
    break;

  case str2int("f3"):
    result = this->f3(is, os);
    break;

  case str2int("f5"):
    result = this->f5(is, os);
    break;

  case str2int("f6"):
    result = this->f6(is, os);
    break;
  };

  return result;
}

bool test_p_caller_stream::f0(CompoMe::Function_stream_recv &is,
                              CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f0();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_p_caller_stream::f1(CompoMe::Function_stream_recv &is,
                              CompoMe::Return_stream_send &os) {

  double l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f1(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_p_caller_stream::f2(CompoMe::Function_stream_recv &is,
                              CompoMe::Return_stream_send &os) {

  i8 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f2(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_p_caller_stream::f3(CompoMe::Function_stream_recv &is,
                              CompoMe::Return_stream_send &os) {

  i16 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f3(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_p_caller_stream::f5(CompoMe::Function_stream_recv &is,
                              CompoMe::Return_stream_send &os) {

  i32 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f5(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_p_caller_stream::f6(CompoMe::Function_stream_recv &is,
                              CompoMe::Return_stream_send &os) {

  i64 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f6(l_a);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}
