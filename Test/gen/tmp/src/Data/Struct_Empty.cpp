#include "Data/Types.hpp"

#include "Data/Struct_Empty.hpp"

#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Empty *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, Empty *&c) {
  std::string t = get_type(is);
  if (t != "Empty"

  ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <Empty>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Empty &c) {
  os << "{"
     << "type:"
     << "Empty,"
     << "}";
  return os;
}

std::istream &operator>>(std::istream &is, Empty &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "Empty") {
    std::cerr << "ERREUR TYPE:"
              << ">Empty< != >" << type << "<" << std::endl;
  }

  is.ignore(1, '}');

  return is;
}

Empty::Empty()

{}

void Empty::to_stream(std::ostream &os) const { os << *this; }