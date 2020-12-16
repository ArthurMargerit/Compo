#include "Interfaces/org/mpris/MediaPlayer2/Player/Player_fake_dbus.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

namespace org {

namespace mpris {

namespace MediaPlayer2 {

Player::T_p_dbus Player::get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                       CompoMe::Return_dbus_recv &rs) {
  Player_fake_dbus *a = new Player_fake_dbus(fs, rs);
  std::tuple<Player_fake_dbus *, CompoMe::Fake_dbus *, Player *> rr(a, a, a);
  return rr;
}

Player_fake_dbus::Player_fake_dbus(CompoMe::Function_dbus_send &out,
                                   CompoMe::Return_dbus_recv &in)
    : CompoMe::Fake_dbus(out, in) {}

Player_fake_dbus::~Player_fake_dbus() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Player ////////////////////////////////////////////////

void Player_fake_dbus::Next() {
  this->get_o().start();
  this->get_o().set_function("Next");
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

void Player_fake_dbus::Previous() {
  this->get_o().start();
  this->get_o().set_function("Previous");
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

void Player_fake_dbus::PlayPause() {
  this->get_o().start();
  this->get_o().set_function("PlayPause");
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

void Player_fake_dbus::Play() {
  this->get_o().start();
  this->get_o().set_function("Play");
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

void Player_fake_dbus::Pause() {
  this->get_o().start();
  this->get_o().set_function("Pause");
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

void Player_fake_dbus::OpenUri(CompoMe::String Uri) {
  this->get_o().start();
  this->get_o().set_function("OpenUri");
  CompoMe::Serialization_context_export p_ctx;
  this->get_o() << Uri;
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

void Player_fake_dbus::Seek(i64 offset) {
  this->get_o().start();
  this->get_o().set_function("Seek");
  CompoMe::Serialization_context_export p_ctx;
  this->get_o() << offset;
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

void Player_fake_dbus::Stop() {
  this->get_o().start();
  this->get_o().set_function("Stop");
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

// INTERFACE get/set Player /////////////////////////////////////////////////

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
