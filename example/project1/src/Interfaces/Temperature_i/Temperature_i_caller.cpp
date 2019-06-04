
#include "Interfaces/Temperature_i/Temperature_i_caller.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Temperature_i_caller::Temperature_i_caller(Temperature_i &pcomp)
    : Caller(), comp(pcomp) {
  return;
}

bool Temperature_i_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');
  this->call(name_function, is, os);
  std::getline(is, name_function);
  return false;
}

bool Temperature_i_caller::call(std::string &name_function, Function_stream &is,
                                Return_stream &os) {
  switch (str2int(name_function.c_str())) {

  case str2int("get"):
    this->get(is, os);
    return true;
    break;
  };

  return false;
}

void Temperature_i_caller::get(Function_stream &is, Return_stream &os) {

  std::string l;
  std::getline(is, l);

  os << this->comp.get();

  return;
}
