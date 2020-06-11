#include "Interfaces/I1/I1_fake.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

I1_fake::I1_fake(Function_stream_send &out, Return_stream_recv &in)
    : Fake(out, in) {}

I1_fake::~I1_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function I1 ////////////////////////////////////////////////

void I1_fake::f1() {
  this->get_o().start();
  this->get_o() << "f1("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

int I1_fake::f2() {
  this->get_o().start();
  this->get_o() << "f2("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  int ri = int();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

int I1_fake::f3(int a) {
  this->get_o().start();
  this->get_o() << "f3(" << a << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  int ri = int();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

int I1_fake::f4(int a, int b) {
  this->get_o().start();
  this->get_o() << "f4(" << a << "," << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  int ri = int();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set I1 /////////////////////////////////////////////////
