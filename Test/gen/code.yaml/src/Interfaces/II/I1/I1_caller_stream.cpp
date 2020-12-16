
#include "Interfaces/II/I1/I1_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace II {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

I1_caller_stream::I1_caller_stream(I1 &pcomp) : Caller_stream(), comp(pcomp) {
  return;
}

bool I1_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool I1_caller_stream::call(std::string &name_function,
                            CompoMe::Function_stream_recv &is,
                            CompoMe::Return_stream_send &os) {
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

  case str2int("get_v"):
    result = this->get_v(is, os);
    break;

  case str2int("set_v"):
    result = this->set_v(is, os);
    break;
  };

  return result;
}

bool I1_caller_stream::f1(CompoMe::Function_stream_recv &is,
                          CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.f1();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool I1_caller_stream::f2(CompoMe::Function_stream_recv &is,
                          CompoMe::Return_stream_send &os) {

  B::i l_a;
  is >> l_a;
  is.get();

  B::i l_b;
  is >> l_b;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.f2(l_a, l_b);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool I1_caller_stream::f3(CompoMe::Function_stream_recv &is,
                          CompoMe::Return_stream_send &os) {

  S1 l_a;
  is >> l_a;
  is.get();

  S::S2 l_b;
  is >> l_b;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.f3(l_a, l_b);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool I1_caller_stream::get_v(CompoMe::Function_stream_recv &is,
                             CompoMe::Return_stream_send &os) {
  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {
    os << this->comp.get_v();
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool I1_caller_stream::set_v(CompoMe::Function_stream_recv &is,
                             CompoMe::Return_stream_send &os) {
  B::i set_val;
  is >> set_val;

  char l = is.get();
  if (l != ')') {
    return false;
  }

  try {
    this->comp.set_v(set_val);
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace II
