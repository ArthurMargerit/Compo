#include "Interfaces/Embded/IO/Pin_in/Pin_in_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace Embded {

namespace IO {

Pin_in::T_p_stream Pin_in::get_fake_stream(CompoMe::Function_stream_send &fs,
                                           CompoMe::Return_stream_recv &rs) {
  Pin_in_fake_stream *a = new Pin_in_fake_stream(fs, rs);
  std::tuple<Pin_in_fake_stream *, CompoMe::Fake_stream *, Pin_in *> rr(a, a,
                                                                        a);
  return rr;
}

Pin_in_fake_stream::Pin_in_fake_stream(CompoMe::Function_stream_send &out,
                                       CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Pin_in_fake_stream::~Pin_in_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Pin_in ////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Pin_in /////////////////////////////////////////////////
Embded::IO::Pin_State Pin_in_fake_stream::get_state() const {
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

void Pin_in_fake_stream::set_state(const Embded::IO::Pin_State &state) {
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
