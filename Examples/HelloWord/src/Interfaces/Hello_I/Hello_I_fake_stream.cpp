#include "Interfaces/Hello_I/Hello_I_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

Hello_I::T_p_stream Hello_I::get_fake_stream(CompoMe::Function_stream_send &fs,
                                             CompoMe::Return_stream_recv &rs) {
  Hello_I_fake_stream *a = new Hello_I_fake_stream(fs, rs);
  std::tuple<Hello_I_fake_stream *, CompoMe::Fake_stream *, Hello_I *> rr(a, a,
                                                                          a);
  return rr;
}

Hello_I_fake_stream::Hello_I_fake_stream(CompoMe::Function_stream_send &out,
                                         CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Hello_I_fake_stream::~Hello_I_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Hello_I ////////////////////////////////////////////////

CompoMe::String Hello_I_fake_stream::hello(CompoMe::String who) {
  this->get_o().start();
  this->get_o() << "hello(" << who << ")";
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

// INTERFACE get/set Hello_I /////////////////////////////////////////////////
