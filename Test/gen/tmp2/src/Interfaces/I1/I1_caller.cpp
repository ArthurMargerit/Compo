
#include "Interfaces/I1/I1_caller.hpp"
#include "Errors/Error.hpp"
#include "Errors/Error_fac.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

I1_caller::I1_caller(I1 &pcomp) : Caller(), comp(pcomp) { return; }

bool I1_caller::call(Function_stream &is, Return_stream &os) {
  is.start();

  std::string name_function;
  std::getline(is, name_function, '(');
  bool b = this->call(name_function, is, os);

  std::string end_function;
  std::getline(is, end_function);
  if (end_function != "") {
    b = false;
  }

  os.end();
  return b;
}

bool I1_caller::call(std::string &name_function, Function_stream &is,
                     Return_stream &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {};

  return result;
}
