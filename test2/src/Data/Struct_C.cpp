#include "Data/Struct_C.hpp"
#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const C *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, C *&c) {
  std::string t = get_type(is);
  if (t != "C"

      && t != "D"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <C>\n";

    std::cerr << "\t" << t << " is not one of child type {'D'}\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const C &c) {
  os << "{"
     << "type:"
     << "C,"
     << "parrent:" << (B)c << ","
     << "}";
  return os;
}

std::istream &operator>>(std::istream &is, C &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "C") {
    std::cerr << "ERREUR TYPE:"
              << ">C< != >" << type << "<" << std::endl;
  }
  is.ignore(100, ':') >> (B &)c;
  is.ignore(1, '}');

  return is;
}

C::C()

{}

void C::to_stream(std::ostream &os) const { os << *this; }