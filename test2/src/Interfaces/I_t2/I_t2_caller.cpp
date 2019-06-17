
#include "Interfaces/I_t2/I_t2_caller.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

I_t2_caller::I_t2_caller(I_t2 &pcomp) : I_t1_caller(pcomp), comp(pcomp) {
  return;
}

bool I_t2_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');
  bool b = this->call(name_function, is, os);
  std::getline(is, name_function);
  return b;
}

bool I_t2_caller::call(std::string &name_function, Function_stream &is,
                       Return_stream &os) {
  switch (str2int(name_function.c_str())) {

  default:
    return I_t1_caller::call(name_function, is, os);
    break;
  };

  return false;
}
