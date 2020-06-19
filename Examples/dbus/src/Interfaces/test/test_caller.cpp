
#include "Interfaces/test/test_caller.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

test_caller::test_caller(test &pcomp) : test_p_caller(pcomp), comp(pcomp) {
  return;
}

bool test_caller::call(Function_stream_recv &is, Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool test_caller::call(std::string &name_function, Function_stream_recv &is,
                       Return_stream_send &os) {
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
    return test_p_caller::call(name_function, is, os);
    break;
  };

  return result;
}

bool test_caller::f7(Function_stream_recv &is, Return_stream_send &os) {

  u8 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f7(l_a);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller::f8(Function_stream_recv &is, Return_stream_send &os) {

  u16 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f8(l_a);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller::f9(Function_stream_recv &is, Return_stream_send &os) {

  u32 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f9(l_a);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller::f10(Function_stream_recv &is, Return_stream_send &os) {

  u64 l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f10(l_a);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller::get_a(Function_stream_recv &is, Return_stream_send &os) {
  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {
    os << this->comp.get_a();
  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller::set_a(Function_stream_recv &is, Return_stream_send &os) {
  i32 set_val;
  is >> set_val;

  char l = is.get();
  if (l != ')') {
    return false;
  }

  try {
    this->comp.set_a(set_val);
  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller::get_b(Function_stream_recv &is, Return_stream_send &os) {
  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {
    os << this->comp.get_b();
  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool test_caller::set_b(Function_stream_recv &is, Return_stream_send &os) {
  i64 set_val;
  is >> set_val;

  char l = is.get();
  if (l != ')') {
    return false;
  }

  try {
    this->comp.set_b(set_val);
  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}
