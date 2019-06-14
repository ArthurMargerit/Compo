#include "Data/Struct_B.hpp"
#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const B *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, B *&c) {
  std::string t = get_type(is);
  if (t != "B"

      && t != "C"

      && t != "D"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <B>\n";

    std::cerr << "\t" << t << " is not one of child type {'C', 'D'}\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const B &c) {
  os << "{"
     << "type:"
     << "B,"
     << "parrent:" << (A)c << ","
     << "}";
  return os;
}

std::istream &operator>>(std::istream &is, B &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "B") {
    std::cerr << "ERREUR TYPE:"
              << ">B< != >" << type << "<" << std::endl;
  }
  is.ignore(100, ':') >> (A &)c;
  is.ignore(1, '}');

  return is;
}

B::B()

{}

void B::to_stream(std::ostream &os) const { os << *this; }