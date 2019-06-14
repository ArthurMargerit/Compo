
#include "Interfaces/I_t4/I_t4_caller.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

I_t4_caller::I_t4_caller(I_t4 &pcomp) : Caller(), comp(pcomp) { return; }

bool I_t4_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');
  bool b = this->call(name_function, is, os);
  std::getline(is, name_function);
  return b;
}

bool I_t4_caller::call(std::string &name_function, Function_stream &is,
                       Return_stream &os) {
  switch (str2int(name_function.c_str())) {};

  return false;
}
