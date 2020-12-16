#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_fake_dbus.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

namespace org {

namespace mpris {

namespace MediaPlayer2 {

Ctl::T_p_dbus Ctl::get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                 CompoMe::Return_dbus_recv &rs) {
  Ctl_fake_dbus *a = new Ctl_fake_dbus(fs, rs);
  std::tuple<Ctl_fake_dbus *, CompoMe::Fake_dbus *, Ctl *> rr(a, a, a);
  return rr;
}

Ctl_fake_dbus::Ctl_fake_dbus(CompoMe::Function_dbus_send &out,
                             CompoMe::Return_dbus_recv &in)
    : CompoMe::Fake_dbus(out, in) {}

Ctl_fake_dbus::~Ctl_fake_dbus() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Ctl ////////////////////////////////////////////////

void Ctl_fake_dbus::Quit() {
  this->get_o().start();
  this->get_o().set_function("Quit");
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

  this->get_i().end();
  return;
}

void Ctl_fake_dbus::Raise() {
  this->get_o().start();
  this->get_o().set_function("Raise");
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

  this->get_i().end();
  return;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Ctl /////////////////////////////////////////////////

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
