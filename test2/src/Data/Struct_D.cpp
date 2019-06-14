#include "Data/Struct_D.hpp"
#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const D *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, D *&c) {
  std::string t = get_type(is);
  if (t != "D"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <D>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const D &c) {
  os << "{"
     << "type:"
     << "D,"
     << "parrent:" << (C)c << ","
     << "}";
  return os;
}

std::istream &operator>>(std::istream &is, D &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "D") {
    std::cerr << "ERREUR TYPE:"
              << ">D< != >" << type << "<" << std::endl;
  }
  is.ignore(100, ':') >> (C &)c;
  is.ignore(1, '}');

  return is;
}

D::D()

{}

void D::to_stream(std::ostream &os) const { os << *this; }