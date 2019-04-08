
#include "Interfaces/Hello_Interface/Hello_Interface_caller.hpp"

#include <iostream>
#include <istream>
#include <ostream>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Hello_Interface_caller::Hello_Interface_caller(Hello_Interface &pcomp)
    : comp(pcomp) {

  return;
}

bool Hello_Interface_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');

  switch (str2int(name_function.c_str())) {

  case str2int("hello_word"):
    this->hello_word(is, os);
    return true;
    break;
  };

  std::getline(is, name_function);

  return false;
}

void Hello_Interface_caller::hello_word(Function_stream &is,
                                        Return_stream &os) {

  std::string l;
  std::getline(is, l);

  os << this->comp.hello_word();
  return;
}
