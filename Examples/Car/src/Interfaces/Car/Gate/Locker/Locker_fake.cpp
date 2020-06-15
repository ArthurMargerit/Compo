#include "Interfaces/Car/Gate/Locker/Locker_fake.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

namespace Car {

namespace Gate {

Locker_fake::Locker_fake(Function_stream_send &out, Return_stream_recv &in)
    : Fake(out, in) {}

Locker_fake::~Locker_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Locker ////////////////////////////////////////////////

void Locker_fake::open_window() {
  this->get_o().start();
  this->get_o() << "open_window("
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

void Locker_fake::close_window() {
  this->get_o().start();
  this->get_o() << "close_window("
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

string Locker_fake::state() {
  this->get_o().start();
  this->get_o() << "state("
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

  string ri = string();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Locker /////////////////////////////////////////////////

} // namespace Gate

} // namespace Car
