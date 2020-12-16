#include "Interfaces/Car/Gate/Window/Window_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace Car {

namespace Gate {

Window::T_p_stream Window::get_fake_stream(CompoMe::Function_stream_send &fs,
                                           CompoMe::Return_stream_recv &rs) {
  Window_fake_stream *a = new Window_fake_stream(fs, rs);
  std::tuple<Window_fake_stream *, CompoMe::Fake_stream *, Window *> rr(a, a,
                                                                        a);
  return rr;
}

Window_fake_stream::Window_fake_stream(CompoMe::Function_stream_send &out,
                                       CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Window_fake_stream::~Window_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Window ////////////////////////////////////////////////

void Window_fake_stream::lock() {
  this->get_o().start();
  this->get_o() << "lock("
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

void Window_fake_stream::unlock() {
  this->get_o().start();
  this->get_o() << "unlock("
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

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Window /////////////////////////////////////////////////
ui8 Window_fake_stream::get_percent() const {
  this->get_o().start();
  this->get_o() << "get_percent()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  ui8 ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void Window_fake_stream::set_percent(const ui8 &percent) {
  this->get_o().start();
  this->get_o() << "set_percent(" << percent << ")";
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

} // namespace Gate

} // namespace Car
