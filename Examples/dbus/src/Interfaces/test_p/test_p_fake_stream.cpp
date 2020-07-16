#include "Interfaces/test_p/test_p_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

test_p::T_p_stream test_p::get_fake_stream(CompoMe::Function_stream_send &fs,
                                           CompoMe::Return_stream_recv &rs) {
  test_p_fake_stream *a = new test_p_fake_stream(fs, rs);
  std::tuple<test_p_fake_stream *, CompoMe::Fake_stream *, test_p *> rr(a, a,
                                                                        a);
  return rr;
}

test_p_fake_stream::test_p_fake_stream(CompoMe::Function_stream_send &out,
                                       CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

test_p_fake_stream::~test_p_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function test_p ////////////////////////////////////////////////

void test_p_fake_stream::f0() {
  this->get_o().start();
  this->get_o() << "f0("
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

  return;
}

void test_p_fake_stream::f1(double a) {
  this->get_o().start();
  this->get_o() << "f1(" << a << ")";
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

void test_p_fake_stream::f2(i8 a) {
  this->get_o().start();
  this->get_o() << "f2(" << a << ")";
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

void test_p_fake_stream::f3(i16 a) {
  this->get_o().start();
  this->get_o() << "f3(" << a << ")";
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

void test_p_fake_stream::f5(i32 a) {
  this->get_o().start();
  this->get_o() << "f5(" << a << ")";
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

void test_p_fake_stream::f6(i64 a) {
  this->get_o().start();
  this->get_o() << "f6(" << a << ")";
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

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set test_p /////////////////////////////////////////////////
