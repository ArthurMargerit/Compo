#include "Data/Types.hpp"

#include "Data/Struct_A.hpp"

#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const A *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, A *&c) {
  std::string t = get_type(is);
  if (t != "A"

  ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <A>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const A &c) {
  os << "{"
     << "type:"
     << "A,"
     << "a:" << c.a << "}";
  return os;
}

std::istream &operator>>(std::istream &is, A &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "A") {
    std::cerr << "ERREUR TYPE:"
              << ">A< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.a;
  is.ignore(1, '}');

  return is;
}

A::A(int p_a) : a(p_a) {}

A::A()
    : a(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {}
int A::get_a() const { return this->a; }

void A::set_a(const int value) { this->a = value; }

void A::to_stream(std::ostream &os) const { os << *this; }