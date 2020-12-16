#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace org {

namespace freedesktop {

namespace Dbus {

Introspectable::T_p_stream
Introspectable::get_fake_stream(CompoMe::Function_stream_send &fs,
                                CompoMe::Return_stream_recv &rs) {
  Introspectable_fake_stream *a = new Introspectable_fake_stream(fs, rs);
  std::tuple<Introspectable_fake_stream *, CompoMe::Fake_stream *,
             Introspectable *>
      rr(a, a, a);
  return rr;
}

Introspectable_fake_stream::Introspectable_fake_stream(
    CompoMe::Function_stream_send &out, CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Introspectable_fake_stream::~Introspectable_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Introspectable
// ////////////////////////////////////////////////

CompoMe::String Introspectable_fake_stream::Introspect() {
  this->get_o().start();
  this->get_o() << "Introspect("
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

// INTERFACE get/set Introspectable
// /////////////////////////////////////////////////

} // namespace Dbus

} // namespace freedesktop

} // namespace org
