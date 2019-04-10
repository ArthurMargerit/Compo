
#include "Interfaces/Log_i/Log_i_caller.hpp"

#include <iostream>
#include <istream>
#include <ostream>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Log_i_caller::Log_i_caller(Log_i &pcomp) : comp(pcomp) { return; }

bool Log_i_caller::call(Function_stream &is, Return_stream &os) {

  std::string name_function;

  std::getline(is, name_function, '(');

  switch (str2int(name_function.c_str())) {

  case str2int("info"):
    this->info(is, os);
    return true;
    break;

  case str2int("debug"):
    this->debug(is, os);
    return true;
    break;

  case str2int("warning"):
    this->warning(is, os);
    return true;
    break;

  case str2int("error"):
    this->error(is, os);
    return true;
    break;

  case str2int("log"):
    this->log(is, os);
    return true;
    break;
  };

  std::getline(is, name_function);

  return false;
}

void Log_i_caller::info(Function_stream &is, Return_stream &os) {

  String l_mess;
  is >> l_mess;

  std::string l;
  std::getline(is, l);

  os << this->comp.info(l_mess);
  return;
}

void Log_i_caller::debug(Function_stream &is, Return_stream &os) {

  String l_mess;
  is >> l_mess;

  std::string l;
  std::getline(is, l);

  os << this->comp.debug(l_mess);
  return;
}

void Log_i_caller::warning(Function_stream &is, Return_stream &os) {

  String l_mess;
  is >> l_mess;

  std::string l;
  std::getline(is, l);

  os << this->comp.warning(l_mess);
  return;
}

void Log_i_caller::error(Function_stream &is, Return_stream &os) {

  String l_mess;
  is >> l_mess;

  std::string l;
  std::getline(is, l);

  os << this->comp.error(l_mess);
  return;
}

void Log_i_caller::log(Function_stream &is, Return_stream &os) {

  Log_s l_mess;
  is >> l_mess;

  std::string l;
  std::getline(is, l);

  os << this->comp.log(l_mess);
  return;
}
