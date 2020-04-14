#include "Interfaces/I1/I1_fake.hpp"
#include "Errors/Error.hpp"

I1_fake::I1_fake(Function_stream &out, Return_stream &in) : Fake(out, in) {}

I1_fake::~I1_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function I1 ////////////////////////////////////////////////

void I1_fake::f() {
  this->get_o().start();
  this->get_o() << "f("

                << ")";
  this->get_o().call();

  this->get_i().pull();
}

void I1_fake::f1() {
  this->get_o().start();
  this->get_o() << "f1("

                << ")";
  this->get_o().call();

  this->get_i().pull();
}

void I1_fake::f2(i32 a) {
  this->get_o().start();
  this->get_o() << "f2("

                << a

                << ")";
  this->get_o().call();

  this->get_i().pull();
}

void I1_fake::f3(i32 a, i32 b) {
  this->get_o().start();
  this->get_o() << "f3("

                << a << ","

                << b

                << ")";
  this->get_o().call();

  this->get_i().pull();
}

i32 I1_fake::f4() {
  this->get_o().start();
  this->get_o() << "f4("

                << ")";
  this->get_o().call();

  this->get_i().pull();

  i32 ri = i32();

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

i32 I1_fake::f5(i32 a) {
  this->get_o().start();
  this->get_o() << "f5("

                << a

                << ")";
  this->get_o().call();

  this->get_i().pull();

  i32 ri = i32();

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
