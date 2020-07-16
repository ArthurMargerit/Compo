#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_fake_dbus.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

namespace org {

namespace freedesktop {

namespace Dbus {

Introspectable::T_p_dbus
Introspectable::get_fake_dbus(CompoMe::Function_dbus_send &fs,
                              CompoMe::Return_dbus_recv &rs) {
  Introspectable_fake_dbus *a = new Introspectable_fake_dbus(fs, rs);
  std::tuple<Introspectable_fake_dbus *, CompoMe::Fake_dbus *, Introspectable *>
      rr(a, a, a);
  return rr;
}

Introspectable_fake_dbus::Introspectable_fake_dbus(
    CompoMe::Function_dbus_send &out, CompoMe::Return_dbus_recv &in)
    : CompoMe::Fake_dbus(out, in) {}

Introspectable_fake_dbus::~Introspectable_fake_dbus() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Introspectable
// ////////////////////////////////////////////////

string Introspectable_fake_dbus::Introspect() {
  this->get_o().start();
  this->get_o().set_function("Introspect");
  CompoMe::Serialization_context_export p_ctx;
  this->get_o().send();

  this->get_i().pull();
  // TODO: error
  // // if(this->get_i().get_si().peek() == '!') {
  // //   this->get_i().get_si().get(); // remove !
  // //   std::shared_ptr<Error> l_e;
  // //   this->get_i() >> l_e;
  //   this->get_i().end();
  //   //l_e->real();
  //   //    }

  CompoMe::Serialization_context_import p_ctx_i;
  string ri = string();
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
