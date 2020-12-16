
#include "Interfaces/Calc_I/Calc_I_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Calc_I_caller_stream::Calc_I_caller_stream(Calc_I &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Calc_I_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool Calc_I_caller_stream::call(std::string &name_function,
                                CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {
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

bool Calc_I_caller_stream::add(CompoMe::Function_stream_recv &is,
                               CompoMe::Return_stream_send &os) {

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

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Calc_I_caller_stream::sub(CompoMe::Function_stream_recv &is,
                               CompoMe::Return_stream_send &os) {

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

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Calc_I_caller_stream::time(CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {

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

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Calc_I_caller_stream::div(CompoMe::Function_stream_recv &is,
                               CompoMe::Return_stream_send &os) {

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

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}
