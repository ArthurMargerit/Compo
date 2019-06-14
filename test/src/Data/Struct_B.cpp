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

      && t != "B_2_1"

      && t != "B_1"

      && t != "B_2"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <B>\n";

    std::cerr << "\t" << t
              << " is not one of child type {'B_2_1', 'B_1', 'B_2'}\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const B &c) {
  os << "{"
     << "type:"
     << "B,"
     << "a:" << c.a << ","
     << "b:" << c.b << ","
     << "c:" << c.c << "}";
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

  is.ignore(100, ':') >> c.a;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.b;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.c;
  is.ignore(1, '}');

  return is;
}

B::B(int p_a, int p_b, A p_c) : a(p_a), b(p_b), c(p_c) {}

B::B()
    : a(0), b(0), c(
                      /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {}
int B::get_a() const { return this->a; }

void B::set_a(const int value) { this->a = value; }
int B::get_b() const { return this->b; }

void B::set_b(const int value) { this->b = value; }
A B::get_c() const { return this->c; }

void B::set_c(const A value) { this->c = value; }
void B::action1() { return; }

void B::action2(int a) { return; }

int B::action3() { return 0; }

int B::action4(int a) { return 0; }

int B::action5(int a, int b) { return 0; }

void B::to_stream(std::ostream &os) const { os << *this; }