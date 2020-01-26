#include "Interfaces/I1/I1_fake.hpp"
#include "Errors/Error.hpp"

I1_fake::I1_fake(Function_stream &out, Return_stream &in) : Fake(out, in) {}

I1_fake::~I1_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function I1 ////////////////////////////////////////////////

void I1_fake::f1() {
  this->get_o().start();
  this->get_o() << "f1("

                << ")";
  this->get_o().call();

  this->get_i().pull();
}

int I1_fake::f3() {
  this->get_o().start();
  this->get_o() << "f3("

                << ")";
  this->get_o().call();

  this->get_i().pull();

  int ri = int();

  if (this->get_i().get_si()->peek() == '!') {
    this->get_i().get_si()->get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    l_e->real();
  } else {
    this->get_i() >> ri;
  }

  this->get_i().end();
  return ri;
}

void I1_fake::f2(int p1) {
  this->get_o().start();
  this->get_o() << "f2("

                << p1

                << ")";
  this->get_o().call();

  this->get_i().pull();
}

int I1_fake::f4(int p1) {
  this->get_o().start();
  this->get_o() << "f4("

                << p1

                << ")";
  this->get_o().call();

  this->get_i().pull();

  int ri = int();

  if (this->get_i().get_si()->peek() == '!') {
    this->get_i().get_si()->get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    l_e->real();
  } else {
    this->get_i() >> ri;
  }

  this->get_i().end();
  return ri;
}

int I1_fake::f5(int p1, int p2) {
  this->get_o().start();
  this->get_o() << "f5("

                << p1 << ","

                << p2

                << ")";
  this->get_o().call();

  this->get_i().pull();

  int ri = int();

  if (this->get_i().get_si()->peek() == '!') {
    this->get_i().get_si()->get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    l_e->real();
  } else {
    this->get_i() >> ri;
  }

  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set I1 /////////////////////////////////////////////////
int I1_fake::get_a() const {
  this->get_o().start();
  this->get_o() << "get_a()";
  this->get_o().call();

  this->get_i().pull();
  if (this->get_i().get_si()->peek() == '!') {
    this->get_i().get_si()->get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    l_e->real();
  }

  int ret;
  this->get_i() >> ret;
  this->get_i().end();

  return ret;
}

void I1_fake::set_a(const int &a) {
  this->get_o().start();
  this->get_o() << "set_a(" << a << ")";
  this->get_o().call();

  this->get_i().pull();

  if (this->get_i().get_si()->peek() == '!') {
    this->get_i().get_si()->get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    l_e->real();
  } else {
    std::string empty;
    std::getline(this->get_i(), empty);
    if (empty != "") {
      throw "Error: set return something";
    }
  }
  this->get_i().end();
  return;
}
int I1_fake::get_b() const {
  this->get_o().start();
  this->get_o() << "get_b()";
  this->get_o().call();

  this->get_i().pull();
  if (this->get_i().get_si()->peek() == '!') {
    this->get_i().get_si()->get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    l_e->real();
  }

  int ret;
  this->get_i() >> ret;
  this->get_i().end();

  return ret;
}

void I1_fake::set_b(const int &b) {
  this->get_o().start();
  this->get_o() << "set_b(" << b << ")";
  this->get_o().call();

  this->get_i().pull();

  if (this->get_i().get_si()->peek() == '!') {
    this->get_i().get_si()->get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    l_e->real();
  } else {
    std::string empty;
    std::getline(this->get_i(), empty);
    if (empty != "") {
      throw "Error: set return something";
    }
  }
  this->get_i().end();
  return;
}