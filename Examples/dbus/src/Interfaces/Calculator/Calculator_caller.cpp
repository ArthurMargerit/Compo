
#include "Interfaces/Calculator/Calculator_caller.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Calculator_caller::Calculator_caller(Calculator &pcomp)
    : Caller(), comp(pcomp) {
  return;
}

bool Calculator_caller::call(Function_stream_recv &is, Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool Calculator_caller::call(std::string &name_function,
                             Function_stream_recv &is, Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("add"):
    result = this->add(is, os);
    break;

  case str2int("sub"):
    result = this->sub(is, os);
    break;

  case str2int("time"):
    result = this->time(is, os);
    break;

  case str2int("div"):
    result = this->div(is, os);
    break;
  };

  return result;
}

bool Calculator_caller::add(Function_stream_recv &is, Return_stream_send &os) {

  double l_a;
  is >> l_a;
  is.get();

  double l_b;
  is >> l_b;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.add(l_a, l_b);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Calculator_caller::sub(Function_stream_recv &is, Return_stream_send &os) {

  double l_a;
  is >> l_a;
  is.get();

  double l_b;
  is >> l_b;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.sub(l_a, l_b);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Calculator_caller::time(Function_stream_recv &is, Return_stream_send &os) {

  double l_a;
  is >> l_a;
  is.get();

  double l_b;
  is >> l_b;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.time(l_a, l_b);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Calculator_caller::div(Function_stream_recv &is, Return_stream_send &os) {

  double l_a;
  is >> l_a;
  is.get();

  double l_b;
  is >> l_b;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.div(l_a, l_b);

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}
