#include "Interfaces/Interface_test/Interface_test_fake.hpp"

Interface_test_fake::Interface_test_fake(Function_stream &out,
                                         Return_stream &in)
    : o(out), i(in) {}

Interface_test_fake::~Interface_test_fake() noexcept {}
int Interface_test_fake::f1(int p1, int p2, int p3) {
  o.start();
  o << "f1("

    << p1 << ","

    << p2 << ","

    << p3

    << ")";
  o.call();

  i.pull();

  int ri;
  i >> ri;
  i.end();
  return ri;
}
int Interface_test_fake::f2(int p1, int p2, int p3) {
  o.start();
  o << "f2("

    << p1 << ","

    << p2 << ","

    << p3

    << ")";
  o.call();

  i.pull();

  int ri;
  i >> ri;
  i.end();
  return ri;
}
int Interface_test_fake::f3(int p1, int p2, int p3) {
  o.start();
  o << "f3("

    << p1 << ","

    << p2 << ","

    << p3

    << ")";
  o.call();

  i.pull();

  int ri;
  i >> ri;
  i.end();
  return ri;
}
int Interface_test_fake::get_a() const {
  o.start();
  o << "get_a()";
  o.call();

  i.pull();
  int ret;
  i >> ret;
  i.end();

  return ret;
}

void Interface_test_fake::set_a(const int a) {
  this->a = a;

  o << "set_a(" << a << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}
int Interface_test_fake::get_b() const {
  o.start();
  o << "get_b()";
  o.call();

  i.pull();
  int ret;
  i >> ret;
  i.end();

  return ret;
}

void Interface_test_fake::set_b(const int b) {
  this->b = b;

  o << "set_b(" << b << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}