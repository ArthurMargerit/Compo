#include "Interfaces/II/I1/I1_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace II {

I1::T_p_stream I1::get_fake_stream(CompoMe::Function_stream_send &fs,
                                   CompoMe::Return_stream_recv &rs) {
  I1_fake_stream *a = new I1_fake_stream(fs, rs);
  std::tuple<I1_fake_stream *, CompoMe::Fake_stream *, I1 *> rr(a, a, a);
  return rr;
}

I1_fake_stream::I1_fake_stream(CompoMe::Function_stream_send &out,
                               CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

I1_fake_stream::~I1_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function I1 ////////////////////////////////////////////////

B::i I1_fake_stream::f1() {
  this->get_o().start();
  this->get_o() << "f1("
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

  B::i ri = B::i();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

B::i I1_fake_stream::f2(B::i a, B::i b) {
  this->get_o().start();
  this->get_o() << "f2(" << a << "," << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  B::i ri = B::i();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

B::i I1_fake_stream::f3(S1 a, S::S2 b) {
  this->get_o().start();
  this->get_o() << "f3(" << a << "," << b << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  B::i ri = B::i();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set I1 /////////////////////////////////////////////////
B::i I1_fake_stream::get_v() const {
  this->get_o().start();
  this->get_o() << "get_v()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  B::i ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void I1_fake_stream::set_v(const B::i &v) {
  this->get_o().start();
  this->get_o() << "set_v(" << v << ")";
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

} // namespace II
