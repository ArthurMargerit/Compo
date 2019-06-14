#include "Interfaces/I1/I1_fake.hpp"

I1_fake::I1_fake(Function_stream &out, Return_stream &in) : o(out), i(in) {}

I1_fake::~I1_fake() noexcept {}
int I1_fake::add(int x, int y) {
  o.start();
  o << "add("

    << x << ","

    << y

    << ")";
  o.call();

  i.pull();

  int ri;
  i >> ri;
  i.end();
  return ri;
}
int I1_fake::get_a() const {
  o.start();
  o << "get_a()";
  o.call();

  i.pull();
  int ret;
  i >> ret;
  i.end();

  return ret;
}

void I1_fake::set_a(const int a) {
  this->a = a;

  o << "set_a(" << a << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}