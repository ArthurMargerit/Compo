#include "Data/Struct_A.hpp"
#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const A *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, A *&c) {
  std::string t = get_type(is);
  if (t != "A"

      && t != "B"

      && t != "C"

      && t != "D"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <A>\n";

    std::cerr << "\t" << t << " is not one of child type {'B', 'C', 'D'}\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const A &c) {
  os << "{"
     << "type:"
     << "A,"
     << "}";
  return os;
}

std::istream &operator>>(std::istream &is, A &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "A") {
    std::cerr << "ERREUR TYPE:"
              << ">A< != >" << type << "<" << std::endl;
  }

  is.ignore(1, '}');

  return is;
}

A::A()

{}

void A::to_stream(std::ostream &os) const { os << *this; }