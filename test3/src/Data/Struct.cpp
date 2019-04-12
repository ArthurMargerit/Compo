
#include "Data/Struct.hpp"

#include "Data/Struct_Pair.hpp"

#include "Data/Struct_A.hpp"

#include "Data/Struct_B.hpp"

#include "Data/Struct_B_1.hpp"

#include "Data/Struct_B_2.hpp"

#include "Data/Struct_B_2_1.hpp"

#include "Data/Struct_C.hpp"

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

  case str2int("Pair"): {
    Pair *v = new Pair();
    is >> *v;
    c = v;
    break;
  }

  case str2int("A"): {
    A *v = new A();
    is >> *v;
    c = v;
    break;
  }

  case str2int("B"): {
    B *v = new B();
    is >> *v;
    c = v;
    break;
  }

  case str2int("B_1"): {
    B_1 *v = new B_1();
    is >> *v;
    c = v;
    break;
  }

  case str2int("B_2"): {
    B_2 *v = new B_2();
    is >> *v;
    c = v;
    break;
  }

  case str2int("B_2_1"): {
    B_2_1 *v = new B_2_1();
    is >> *v;
    c = v;
    break;
  }

  case str2int("C"): {
    C *v = new C();
    is >> *v;
    c = v;
    break;
  }
  }

  return is;
}