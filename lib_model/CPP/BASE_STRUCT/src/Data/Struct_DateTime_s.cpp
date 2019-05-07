#include "Data/Types.hpp"

#include "Data/Struct_DateTime_s.hpp"

#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const DateTime_s *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, DateTime_s *&c) {
  std::string t = get_type(is);
  if (t != "DateTime_s"

  ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <DateTime_s>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const DateTime_s &c) {
  os << "{"
     << "type:"
     << "DateTime_s,"
     << "parrent:" << (Date_s)c << ","
     << "}";
  return os;
}

std::istream &operator>>(std::istream &is, DateTime_s &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "DateTime_s") {
    std::cerr << "ERREUR TYPE:"
              << ">DateTime_s< != >" << type << "<" << std::endl;
  }
  is.ignore(100, ':') >> (Date_s &)c;
  is.ignore(1, '}');

  return is;
}

DateTime_s::DateTime_s()

{}

void DateTime_s::to_stream(std::ostream &os) const { os << *this; }