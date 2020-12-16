#include "Interfaces/Car/Gate/Locker/Locker_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace Car {

namespace Gate {

Locker::T_p_stream Locker::get_fake_stream(CompoMe::Function_stream_send &fs,
                                           CompoMe::Return_stream_recv &rs) {
  Locker_fake_stream *a = new Locker_fake_stream(fs, rs);
  std::tuple<Locker_fake_stream *, CompoMe::Fake_stream *, Locker *> rr(a, a,
                                                                        a);
  return rr;
}

Locker_fake_stream::Locker_fake_stream(CompoMe::Function_stream_send &out,
                                       CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Locker_fake_stream::~Locker_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Locker ////////////////////////////////////////////////

void Locker_fake_stream::open_window() {
  this->get_o().start();
  this->get_o() << "open_window("
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

void Locker_fake_stream::close_window() {
  this->get_o().start();
  this->get_o() << "close_window("
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

CompoMe::String Locker_fake_stream::state() {
  this->get_o().start();
  this->get_o() << "state("
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

  CompoMe::String ri = CompoMe::String();
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
