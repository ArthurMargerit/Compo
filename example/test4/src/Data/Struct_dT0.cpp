#include "Data/Struct_dT0.hpp"
#include "Data/Struct_fac_dT0.hpp"

#include <iostream>
#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const dT0 &c) {
  os << "{"
     << "type:"
     << "dT0"

     << ","

     << "m0:" << c.m0 << "}";
  return os;
}

std::istream &operator>>(std::istream &is, dT0 &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "dT0") {
    std::cerr << "ERREUR TYPE:"
              << ">dT0< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.m0;
  is.ignore(1, '}');

  return is;
}

dT0::dT0(Smap<int_tt> p_m0) : m0(p_m0) {}

dT0::dT0()
    : m0(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {}
Smap<int_tt> dT0::get_m0() const { return this->m0; }

void dT0::set_m0(const Smap<int_tt> value) { this->m0 = value; }

void dT0::to_stream(std::ostream &os) const { os << *this; }