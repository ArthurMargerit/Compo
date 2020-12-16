#include "Interfaces/Embded/IO/Pin_out/Pin_out_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace Embded {

namespace IO {

Pin_out::T_p_stream Pin_out::get_fake_stream(CompoMe::Function_stream_send &fs,
                                             CompoMe::Return_stream_recv &rs) {
  Pin_out_fake_stream *a = new Pin_out_fake_stream(fs, rs);
  std::tuple<Pin_out_fake_stream *, CompoMe::Fake_stream *, Pin_out *> rr(a, a,
                                                                          a);
  return rr;
}

Pin_out_fake_stream::Pin_out_fake_stream(CompoMe::Function_stream_send &out,
                                         CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Pin_out_fake_stream::~Pin_out_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Pin_out ////////////////////////////////////////////////

void Pin_out_fake_stream::on() {
  this->get_o().start();
  this->get_o() << "on("
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

void Pin_out_fake_stream::off() {
  this->get_o().start();
  this->get_o() << "off("
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

void Pin_out_fake_stream::set(Embded::IO::Pin_State ps) {
  this->get_o().start();
  this->get_o() << "set(" << ps << ")";
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

void Pin_out_fake_stream::switch_v() {
  this->get_o().start();
  this->get_o() << "switch_v("
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

// INTERFACE get/set Pin_out /////////////////////////////////////////////////
Embded::IO::Pin_State Pin_out_fake_stream::get_state() const {
  this->get_o().start();
  this->get_o() << "get_state()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  Embded::IO::Pin_State ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void Pin_out_fake_stream::set_state(const Embded::IO::Pin_State &state) {
  this->get_o().start();
  this->get_o() << "set_state(" << state << ")";
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

} // namespace IO

} // namespace Embded
