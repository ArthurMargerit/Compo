#include "Data/Types.hpp"

#include "Data/Struct_Complex_s.hpp"

#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Complex_s *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, Complex_s *&c) {
  std::string t = get_type(is);
  if (t != "Complex_s"

  ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <Complex_s>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Complex_s &c) {
  os << "{"
     << "type:"
     << "Complex_s,"
     << "i:" << c.i << ","
     << "r:" << c.r << "}";
  return os;
}

std::istream &operator>>(std::istream &is, Complex_s &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "Complex_s") {
    std::cerr << "ERREUR TYPE:"
              << ">Complex_s< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.i;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.r;
  is.ignore(1, '}');

  return is;
}

Complex_s::Complex_s(double p_i, double p_r) : i(p_i), r(p_r) {}

Complex_s::Complex_s() : i(0.0), r(0.0) {}
double Complex_s::get_i() const { return this->i; }

void Complex_s::set_i(const double value) { this->i = value; }
double Complex_s::get_r() const { return this->r; }

void Complex_s::set_r(const double value) { this->r = value; }

void Complex_s::to_stream(std::ostream &os) const { os << *this; }