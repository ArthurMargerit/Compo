#include "Interfaces/test/test_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

test::T_p_stream test::get_fake_stream(CompoMe::Function_stream_send &fs,
                                       CompoMe::Return_stream_recv &rs) {
  test_fake_stream *a = new test_fake_stream(fs, rs);
  std::tuple<test_fake_stream *, CompoMe::Fake_stream *, test *> rr(a, a, a);
  return rr;
}

test_fake_stream::test_fake_stream(CompoMe::Function_stream_send &out,
                                   CompoMe::Return_stream_recv &in)
    : test_p_fake_stream(out, in) {}

test_fake_stream::~test_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function test_p //////////////////////////////////////

void test_fake_stream::f0() { test_p_fake_stream::f0(); }

void test_fake_stream::f1(double a) { test_p_fake_stream::f1(a); }

void test_fake_stream::f2(i8 a) { test_p_fake_stream::f2(a); }

void test_fake_stream::f3(i16 a) { test_p_fake_stream::f3(a); }

void test_fake_stream::f5(i32 a) { test_p_fake_stream::f5(a); }

void test_fake_stream::f6(i64 a) { test_p_fake_stream::f6(a); }

// INTERFACE Function test ////////////////////////////////////////////////

void test_fake_stream::f7(ui8 a) {
  this->get_o().start();
  this->get_o() << "f7(" << a << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void test_fake_stream::f8(ui16 a) {
  this->get_o().start();
  this->get_o() << "f8(" << a << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void test_fake_stream::f9(ui32 a) {
  this->get_o().start();
  this->get_o() << "f9(" << a << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void test_fake_stream::f10(ui64 a) {
  this->get_o().start();
  this->get_o() << "f10(" << a << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void test_fake_stream::f11(S1 a) {
  this->get_o().start();
  this->get_o() << "f11(" << a << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

S1 test_fake_stream::f12() {
  this->get_o().start();
  this->get_o() << "f12("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  S1 ri = S1();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set test_p ////////////////////////////////////////

// INTERFACE get/set test /////////////////////////////////////////////////
i32 test_fake_stream::get_a() const {
  this->get_o().start();
  this->get_o() << "get_a()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  i32 ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void test_fake_stream::set_a(const i32 &a) {
  this->get_o().start();
  this->get_o() << "set_a(" << a << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  this->get_i().end();
  return;
}
i64 test_fake_stream::get_b() const {
  this->get_o().start();
  this->get_o() << "get_b()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  i64 ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void test_fake_stream::set_b(const i64 &b) {
  this->get_o().start();
  this->get_o() << "set_b(" << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  this->get_i().end();
  return;
}
