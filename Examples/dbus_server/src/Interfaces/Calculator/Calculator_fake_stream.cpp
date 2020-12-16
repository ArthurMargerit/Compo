#include "Interfaces/Calculator/Calculator_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

Calculator::T_p_stream
Calculator::get_fake_stream(CompoMe::Function_stream_send &fs,
                            CompoMe::Return_stream_recv &rs) {
  Calculator_fake_stream *a = new Calculator_fake_stream(fs, rs);
  std::tuple<Calculator_fake_stream *, CompoMe::Fake_stream *, Calculator *> rr(
      a, a, a);
  return rr;
}

Calculator_fake_stream::Calculator_fake_stream(
    CompoMe::Function_stream_send &out, CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Calculator_fake_stream::~Calculator_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Calculator
// ////////////////////////////////////////////////

double Calculator_fake_stream::add(double a, double b) {
  this->get_o().start();
  this->get_o() << "add(" << a << "," << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  double ri = double();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

double Calculator_fake_stream::sub(double a, double b) {
  this->get_o().start();
  this->get_o() << "sub(" << a << "," << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  double ri = double();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

double Calculator_fake_stream::time(double a, double b) {
  this->get_o().start();
  this->get_o() << "time(" << a << "," << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  double ri = double();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

double Calculator_fake_stream::div(double a, double b) {
  this->get_o().start();
  this->get_o() << "div(" << a << "," << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  double ri = double();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Calculator
// /////////////////////////////////////////////////
