#include "Interfaces/Car/Gate/Window/Window_fake.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

namespace Car {

namespace Gate {

Window_fake::Window_fake(Function_stream_send &out, Return_stream_recv &in)
    : Fake(out, in) {}

Window_fake::~Window_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Window ////////////////////////////////////////////////

void Window_fake::lock() {
  this->get_o().start();
  this->get_o() << "lock("
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

void Window_fake::unlock() {
  this->get_o().start();
  this->get_o() << "unlock("
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

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Window /////////////////////////////////////////////////
ui8 Window_fake::get_percent() const {
  this->get_o().start();
  this->get_o() << "get_percent()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  ui8 ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void Window_fake::set_percent(const ui8 &percent) {
  this->get_o().start();
  this->get_o() << "set_percent(" << percent << ")";
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

} // namespace Gate

} // namespace Car
