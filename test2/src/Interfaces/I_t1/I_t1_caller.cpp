
#include "Interfaces/I_t1/I_t1_caller.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

I_t1_caller::I_t1_caller(I_t1 &pcomp) : Caller(), comp(pcomp) { return; }

bool I_t1_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');
  bool b = this->call(name_function, is, os);
  std::getline(is, name_function);
  return b;
}

bool I_t1_caller::call(std::string &name_function, Function_stream &is,
                       Return_stream &os) {
  switch (str2int(name_function.c_str())) {

  case str2int("get_sa"):
    this->get_sa(is, os);
    return true;
    break;
  case str2int("set_sa"):
    this->set_sa(is, os);
    return true;
    break;

  case str2int("get_sb"):
    this->get_sb(is, os);
    return true;
    break;
  case str2int("set_sb"):
    this->set_sb(is, os);
    return true;
    break;

  case str2int("get_sc"):
    this->get_sc(is, os);
    return true;
    break;
  case str2int("set_sc"):
    this->set_sc(is, os);
    return true;
    break;

  case str2int("get_sd"):
    this->get_sd(is, os);
    return true;
    break;
  case str2int("set_sd"):
    this->set_sd(is, os);
    return true;
    break;
  };

  return false;
}

void I_t1_caller::get_sa(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l, ')');
  os << this->comp.get_sa();

  return;
}

void I_t1_caller::set_sa(Function_stream &is, Return_stream &os) {
  A set_val;
  is >> set_val;
  this->comp.set_sa(set_val);

  std::string l;
  std::getline(is, l, ')');

  return;
}

void I_t1_caller::get_sb(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l, ')');
  os << this->comp.get_sb();

  return;
}

void I_t1_caller::set_sb(Function_stream &is, Return_stream &os) {
  B set_val;
  is >> set_val;
  this->comp.set_sb(set_val);

  std::string l;
  std::getline(is, l, ')');

  return;
}

void I_t1_caller::get_sc(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l, ')');
  os << this->comp.get_sc();

  return;
}

void I_t1_caller::set_sc(Function_stream &is, Return_stream &os) {
  C set_val;
  is >> set_val;
  this->comp.set_sc(set_val);

  std::string l;
  std::getline(is, l, ')');

  return;
}

void I_t1_caller::get_sd(Function_stream &is, Return_stream &os) {
  std::string l;
  std::getline(is, l, ')');
  os << this->comp.get_sd();

  return;
}

void I_t1_caller::set_sd(Function_stream &is, Return_stream &os) {
  D set_val;
  is >> set_val;
  this->comp.set_sd(set_val);

  std::string l;
  std::getline(is, l, ')');

  return;
}
