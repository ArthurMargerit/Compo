#include "Data/Types.hpp"

#include "Data/Struct_A1.hpp"

#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const A1 *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, A1 *&c) {
  std::string t = get_type(is);
  if (t != "A1"

  ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <A1>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const A1 &c) {
  os << "{"
     << "type:"
     << "A1,"
     << "a:" << c.a << ","
     << "b:" << c.b << "}";
  return os;
}

std::istream &operator>>(std::istream &is, A1 &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "A1") {
    std::cerr << "ERREUR TYPE:"
              << ">A1< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.a;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.b;
  is.ignore(1, '}');

  return is;
}

A1::A1(int p_a, int p_b) : a(p_a), b(p_b) {}

A1::A1()
    : a(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      b(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {}
int A1::get_a() const { return this->a; }

void A1::set_a(const int value) { this->a = value; }
int A1::get_b() const { return this->b; }

void A1::set_b(const int value) { this->b = value; }

void A1::to_stream(std::ostream &os) const { os << *this; }