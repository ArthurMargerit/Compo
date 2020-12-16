#include "Interfaces/Information_I/Information_I_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

Information_I::T_p_stream
Information_I::get_fake_stream(CompoMe::Function_stream_send &fs,
                               CompoMe::Return_stream_recv &rs) {
  Information_I_fake_stream *a = new Information_I_fake_stream(fs, rs);
  std::tuple<Information_I_fake_stream *, CompoMe::Fake_stream *,
             Information_I *>
      rr(a, a, a);
  return rr;
}

Information_I_fake_stream::Information_I_fake_stream(
    CompoMe::Function_stream_send &out, CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Information_I_fake_stream::~Information_I_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Information_I
// ////////////////////////////////////////////////

CompoMe::String Information_I_fake_stream::get_name() {
  this->get_o().start();
  this->get_o() << "get_name("
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

CompoMe::String Information_I_fake_stream::get_type() {
  this->get_o().start();
  this->get_o() << "get_type("
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

CompoMe::String Information_I_fake_stream::get_location() {
  this->get_o().start();
  this->get_o() << "get_location("
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

// INTERFACE get/set Information_I
// /////////////////////////////////////////////////
