#include "Interfaces/test/test_fake.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

test_fake::test_fake(Function_stream_send &out, Return_stream_recv &in)
    : test_p_fake(out, in) {}

test_fake::~test_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function test_p //////////////////////////////////////

void test_fake::f0() { test_p_fake::f0(); }

void test_fake::f1(double a) { test_p_fake::f1(a); }

void test_fake::f2(i8 a) { test_p_fake::f2(a); }

void test_fake::f3(i16 a) { test_p_fake::f3(a); }

void test_fake::f5(i32 a) { test_p_fake::f5(a); }

void test_fake::f6(i64 a) { test_p_fake::f6(a); }

// INTERFACE Function test ////////////////////////////////////////////////

void test_fake::f7(u8 a) {
  this->get_o().start();
  this->get_o() << "f7(" << a << ")";
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

void test_fake::f8(u16 a) {
  this->get_o().start();
  this->get_o() << "f8(" << a << ")";
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

void test_fake::f9(u32 a) {
  this->get_o().start();
  this->get_o() << "f9(" << a << ")";
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

void test_fake::f10(u64 a) {
  this->get_o().start();
  this->get_o() << "f10(" << a << ")";
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

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set test_p ////////////////////////////////////////

// INTERFACE get/set test /////////////////////////////////////////////////
i32 test_fake::get_a() const {
  this->get_o().start();
  this->get_o() << "get_a()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  i32 ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void test_fake::set_a(const i32 &a) {
  this->get_o().start();
  this->get_o() << "set_a(" << a << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  this->get_i().end();
  return;
}
i64 test_fake::get_b() const {
  this->get_o().start();
  this->get_o() << "get_b()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  i64 ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void test_fake::set_b(const i64 &b) {
  this->get_o().start();
  this->get_o() << "set_b(" << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  this->get_i().end();
  return;
}
