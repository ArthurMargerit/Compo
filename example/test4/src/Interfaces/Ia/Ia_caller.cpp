
#include "Interfaces/Ia/Ia_caller.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Ia_caller::Ia_caller(Ia &pcomp) : Caller(), comp(pcomp) { return; }

bool Ia_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');
  bool b = this->call(name_function, is, os);
  std::getline(is, name_function);
  return b;
}

bool Ia_caller::call(std::string &name_function, Function_stream &is,
                     Return_stream &os) {
  switch (str2int(name_function.c_str())) {

  case str2int("ping"):
    this->ping(is, os);
    return true;
    break;

  case str2int("pp"):
    this->pp(is, os);
    return true;
    break;

  case str2int("p"):
    this->p(is, os);
    return true;
    break;

  case str2int("get_v1"):
    this->get_v1(is, os);
    return true;
    break;
  case str2int("set_v1"):
    this->set_v1(is, os);
    return true;
    break;

  case str2int("get_v2"):
    this->get_v2(is, os);
    return true;
    break;
  case str2int("set_v2"):
    this->set_v2(is, os);
    return true;
    break;
  };

  return false;
}

void Ia_caller::ping(Function_stream &is, Return_stream &os) {

  vec<i> l_p;
  is >> l_p;

  os << this->comp.ping(l_p);

  std::string l;
  std::getline(is, l, ')');

  return;
}

void Ia_caller::pp(Function_stream &is, Return_stream &os) {

  vec<i> l_p1;
  is >> l_p1;
  is.si->get();

  vec<d> l_p2;
  is >> l_p2;

  os << this->comp.pp(l_p1, l_p2);

  std::string l;
  std::getline(is, l, ')');

  return;
}

void Ia_caller::p(Function_stream &is, Return_stream &os) {

  os << this->comp.p();

  std::string l;
  std::getline(is, l, ')');

  return;
}

void Ia_caller::get_v1(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l, ')');
  os << this->comp.get_v1();

  return;
}

void Ia_caller::set_v1(Function_stream &is, Return_stream &os) {
  vec<i> set_val;
  is >> set_val;
  this->comp.set_v1(set_val);

  std::string l;
  std::getline(is, l, ')');

  return;
}

void Ia_caller::get_v2(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l, ')');
  os << this->comp.get_v2();

  return;
}

void Ia_caller::set_v2(Function_stream &is, Return_stream &os) {
  vec<d> set_val;
  is >> set_val;
  this->comp.set_v2(set_val);

  std::string l;
  std::getline(is, l, ')');

  return;
}
