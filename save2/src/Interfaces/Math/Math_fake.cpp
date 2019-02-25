#include "Interfaces/Math/Math_fake.hpp"

Math_fake::Math_fake(std::ostream &out, std::istream &in) : o(out), i(in) {}

Math_fake::~Math_fake() noexcept {}
int Math_fake::add(int a, int b) {
  o << "add("

    << a << ","

    << b

    << ")" << std::endl;

  int ri;
  i >> ri;
  return ri;
}
int Math_fake::time(int a, int b) {
  o << "time("

    << a << ","

    << b

    << ")" << std::endl;

  int ri;
  i >> ri;
  return ri;
}
int Math_fake::sub(int a, int b) {
  o << "sub("

    << a << ","

    << b

    << ")" << std::endl;

  int ri;
  i >> ri;
  return ri;
}
int Math_fake::div(int a, int b) {
  o << "div("

    << a << ","

    << b

    << ")" << std::endl;

  int ri;
  i >> ri;
  return ri;
}
int Math_fake::power(int a, int b) {
  o << "power("

    << a << ","

    << b

    << ")" << std::endl;

  int ri;
  i >> ri;
  return ri;
}
int Math_fake::mod(int a, int b) {
  o << "mod("

    << a << ","

    << b

    << ")" << std::endl;

  int ri;
  i >> ri;
  return ri;
}
