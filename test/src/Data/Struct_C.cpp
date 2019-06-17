#include "Data/Struct_C.hpp"
#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const C *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, C *&c) {
  std::string t = get_type(is);
  if (t != "C"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <C>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const C &c) {
  os << "{"
     << "type:"
     << "C,"
     << "a:" << c.a << ","
     << "b:" << c.b << ","
     << "c:" << c.c << ","
     << "c1:" << c.c1 << ","
     << "c2:" << c.c2 << ","
     << "c3:" << c.c3 << ","
     << "d:" << c.d << "}";
  return os;
}

std::istream &operator>>(std::istream &is, C &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "C") {
    std::cerr << "ERREUR TYPE:"
              << ">C< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.a;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.b;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.c;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.c1;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.c2;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.c3;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.d;
  is.ignore(1, '}');

  return is;
}

C::C(int p_a, int p_b, A p_c, A p_c1, A p_c2, A p_c3, B p_d)
    : a(p_a), b(p_b), c(p_c), c1(p_c1), c2(p_c2), c3(p_c3), d(p_d) {}

C::C()
    : a(0), b(0), c(
                      /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      c1(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      c2(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      c3(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      d(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {}
int C::get_a() const { return this->a; }

void C::set_a(const int value) { this->a = value; }
int C::get_b() const { return this->b; }

void C::set_b(const int value) { this->b = value; }
A C::get_c() const { return this->c; }

void C::set_c(const A value) { this->c = value; }
A C::get_c1() const { return this->c1; }

void C::set_c1(const A value) { this->c1 = value; }
A C::get_c2() const { return this->c2; }

void C::set_c2(const A value) { this->c2 = value; }
A C::get_c3() const { return this->c3; }

void C::set_c3(const A value) { this->c3 = value; }
B C::get_d() const { return this->d; }

void C::set_d(const B value) { this->d = value; }

void C::to_stream(std::ostream &os) const { os << *this; }