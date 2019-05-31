
#include "Interfaces/Temperature_report_i/Temperature_report_i_caller.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Temperature_report_i_caller::Temperature_report_i_caller(
    Temperature_report_i &pcomp)
    : Caller(), comp(pcomp) {
  return;
}

bool Temperature_report_i_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');
  this->call(name_function, is, os);
  std::getline(is, name_function);
  return false;
}

bool Temperature_report_i_caller::call(std::string &name_function,
                                       Function_stream &is, Return_stream &os) {
  switch (str2int(name_function.c_str())) {

  case str2int("notify"):
    this->notify(is, os);
    return true;
    break;
  };

  return false;
}

void Temperature_report_i_caller::notify(Function_stream &is,
                                         Return_stream &os) {

  Temperature_sample l_ts;
  is >> l_ts;

  std::string l;
  std::getline(is, l);

  this->comp.notify(l_ts);

  return;
}
