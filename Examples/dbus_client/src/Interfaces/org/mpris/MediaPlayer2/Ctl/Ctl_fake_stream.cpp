#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace org {

namespace mpris {

namespace MediaPlayer2 {

Ctl::T_p_stream Ctl::get_fake_stream(CompoMe::Function_stream_send &fs,
                                     CompoMe::Return_stream_recv &rs) {
  Ctl_fake_stream *a = new Ctl_fake_stream(fs, rs);
  std::tuple<Ctl_fake_stream *, CompoMe::Fake_stream *, Ctl *> rr(a, a, a);
  return rr;
}

Ctl_fake_stream::Ctl_fake_stream(CompoMe::Function_stream_send &out,
                                 CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Ctl_fake_stream::~Ctl_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Ctl ////////////////////////////////////////////////

void Ctl_fake_stream::Quit() {
  this->get_o().start();
  this->get_o() << "Quit("
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

void Ctl_fake_stream::Raise() {
  this->get_o().start();
  this->get_o() << "Raise("
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

// INTERFACE get/set Ctl /////////////////////////////////////////////////

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
