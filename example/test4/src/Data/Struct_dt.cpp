#include "Data/Struct_dt.hpp"
#include "Data/Struct_fac_dt.hpp"

#include <iostream>
#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const dt &c) {
  os << "{"
     << "type:"
     << "dt"

     << ","

     << "v0:" << c.v0 << ","
     << "v1:" << c.v1 << "}";
  return os;
}

std::istream &operator>>(std::istream &is, dt &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "dt") {
    std::cerr << "ERREUR TYPE:"
              << ">dt< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.v0;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.v1;
  is.ignore(1, '}');

  return is;
}

dt::dt(vec<int_tt> p_v0, vec<int_tt> p_v1) : v0(p_v0), v1(p_v1) {}

dt::dt()
    : v0(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      v1(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {}
vec<int_tt> dt::get_v0() const { return this->v0; }

void dt::set_v0(const vec<int_tt> value) { this->v0 = value; }
vec<int_tt> dt::get_v1() const { return this->v1; }

void dt::set_v1(const vec<int_tt> value) { this->v1 = value; }

void dt::to_stream(std::ostream &os) const { os << *this; }