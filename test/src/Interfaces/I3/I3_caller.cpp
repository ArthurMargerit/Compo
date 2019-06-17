
#include "Interfaces/I3/I3_caller.hpp"

#include <iostream>
#include <istream>
#include <ostream>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

I3_caller::I3_caller(I3 &pcomp) : comp(pcomp) { return; }

bool I3_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');

  switch (str2int(name_function.c_str())) {};

  std::getline(is, name_function);

  return false;
}
