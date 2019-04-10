#include "Data/Types.hpp"

#include "Data/Struct_Date_s.hpp"

#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Date_s *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, Date_s *&c) {
  std::string t = get_type(is);
  if (t != "Date_s"

      && t != "DateTime_s"

  ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <Date_s>\n";

    std::cerr << "\t" << t << " is not one of child type {'DateTime_s'}\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Date_s &c) {
  os << "{"
     << "type:"
     << "Date_s,"
     << "}";
  return os;
}

std::istream &operator>>(std::istream &is, Date_s &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "Date_s") {
    std::cerr << "ERREUR TYPE:"
              << ">Date_s< != >" << type << "<" << std::endl;
  }

  is.ignore(1, '}');

  return is;
}

Date_s::Date_s()

{}

void Date_s::to_stream(std::ostream &os) const { os << *this; }