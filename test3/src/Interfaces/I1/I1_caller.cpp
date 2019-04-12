
#include "Interfaces/I1/I1_caller.hpp"

#include <iostream>
#include <istream>
#include <ostream>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

I1_caller::I1_caller(I1 &pcomp) : comp(pcomp) { return; }

bool I1_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');

  switch (str2int(name_function.c_str())) {

  case str2int("add"):
    this->add(is, os);
    return true;
    break;

  case str2int("get_a"):
    this->get_a(is, os);
    return true;
    break;
  case str2int("set_a"):
    this->set_a(is, os);
    return true;
    break;
  };

  std::getline(is, name_function);

  return false;
}

void I1_caller::add(Function_stream &is, Return_stream &os) {

  int l_x;
  is >> l_x;
  is.si->get();

  int l_y;
  is >> l_y;

  std::string l;
  std::getline(is, l);

  os << this->comp.add(l_x, l_y);

  return;
}

void I1_caller::get_a(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l);
  os << this->comp.get_a();

  return;
}

void I1_caller::set_a(Function_stream &is, Return_stream &os) {
  int set_val;
  is >> set_val;
  this->comp.set_a(set_val);

  std::string l;
  std::getline(is, l);

  return;
}
