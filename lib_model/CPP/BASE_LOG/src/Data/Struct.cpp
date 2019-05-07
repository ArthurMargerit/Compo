
#include "Data/Struct.hpp"

#include "Data/Struct_Log_s.hpp"

#include <iostream>
#include <istream>
#include <string>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &operator<<(std::ostream &os, const Struct *c) {
  os << "*";
  c->to_stream(os);
  return os;
}

std::string get_type(std::istream &is) {
  int tg = is.tellg();
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  is.seekg(tg);
  return type;
}

bool is_pointer(std::istream &is) {
  int tg = is.tellg();
  std::string type;
  char c = is.get();
  is.seekg(tg);
  return c == '*';
}

std::istream &operator>>(std::istream &is, Struct *&c) {

  if (c != NULL) {
    free(c);
  }

  if (!is_pointer(is)) {
    std::cerr << "NOT A POINTER\n";
  }

  std::string t = get_type(is);
  switch (str2int(t.c_str())) {

  case str2int("Log_s"): {
    Log_s *v = new Log_s();
    is >> *v;
    c = v;
    break;
  }
  }

  return is;
}