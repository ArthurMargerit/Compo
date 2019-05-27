
#include "Interfaces/Interface_test/Interface_test_caller.hpp"

#include <iostream>
#include <istream>
#include <ostream>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Interface_test_caller::Interface_test_caller(Interface_test &pcomp)
    : comp(pcomp) {

  return;
}

bool Interface_test_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');

  switch (str2int(name_function.c_str())) {

  case str2int("f1"):
    this->f1(is, os);
    return true;
    break;

  case str2int("f2"):
    this->f2(is, os);
    return true;
    break;

  case str2int("f3"):
    this->f3(is, os);
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

  case str2int("get_b"):
    this->get_b(is, os);
    return true;
    break;
  case str2int("set_b"):
    this->set_b(is, os);
    return true;
    break;
  };

  std::getline(is, name_function);

  return false;
}

void Interface_test_caller::f1(Function_stream &is, Return_stream &os) {

  int l_p1;
  is >> l_p1;
  is.si->get();

  int l_p2;
  is >> l_p2;
  is.si->get();

  int l_p3;
  is >> l_p3;

  std::string l;
  std::getline(is, l);

  os << this->comp.f1(l_p1, l_p2, l_p3);
  return;
}

void Interface_test_caller::f2(Function_stream &is, Return_stream &os) {

  int l_p1;
  is >> l_p1;
  is.si->get();

  int l_p2;
  is >> l_p2;
  is.si->get();

  int l_p3;
  is >> l_p3;

  std::string l;
  std::getline(is, l);

  os << this->comp.f2(l_p1, l_p2, l_p3);
  return;
}

void Interface_test_caller::f3(Function_stream &is, Return_stream &os) {

  int l_p1;
  is >> l_p1;
  is.si->get();

  int l_p2;
  is >> l_p2;
  is.si->get();

  int l_p3;
  is >> l_p3;

  std::string l;
  std::getline(is, l);

  os << this->comp.f3(l_p1, l_p2, l_p3);
  return;
}

void Interface_test_caller::get_a(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l);
  os << this->comp.get_a();

  return;
}

void Interface_test_caller::set_a(Function_stream &is, Return_stream &os) {
  int set_val;
  is >> set_val;
  this->comp.set_a(set_val);

  std::string l;
  std::getline(is, l);

  return;
}

void Interface_test_caller::get_b(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l);
  os << this->comp.get_b();

  return;
}

void Interface_test_caller::set_b(Function_stream &is, Return_stream &os) {
  int set_val;
  is >> set_val;
  this->comp.set_b(set_val);

  std::string l;
  std::getline(is, l);

  return;
}
