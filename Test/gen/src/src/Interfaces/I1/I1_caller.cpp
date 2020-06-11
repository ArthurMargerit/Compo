
#include "Interfaces/I1/I1_caller.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

I1_caller::I1_caller(I1 &pcomp) : Caller(), comp(pcomp) { return; }

bool I1_caller::call(Function_stream_recv &is, Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool I1_caller::call(std::string &name_function, Function_stream_recv &is,
                     Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("f1"):
    result = this->f1(is, os);
    break;

  case str2int("f2"):
    result = this->f2(is, os);
    break;

  case str2int("f3"):
    result = this->f3(is, os);
    break;

  case str2int("f4"):
    result = this->f4(is, os);
    break;
  };

  return result;
}

bool I1_caller::f1(Function_stream_recv &is, Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.f1();

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool I1_caller::f2(Function_stream_recv &is, Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.f2();

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool I1_caller::f3(Function_stream_recv &is, Return_stream_send &os) {

  int l_a;
  is >> l_a;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.f3(l_a);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool I1_caller::f4(Function_stream_recv &is, Return_stream_send &os) {

  int l_a;
  is >> l_a;
  is.get();

  int l_b;
  is >> l_b;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.f4(l_a, l_b);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}
