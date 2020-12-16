#include "Interfaces/CompoMe/Log/Filter_Management_I/Filter_Management_I_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace CompoMe {

namespace Log {

Filter_Management_I::T_p_stream
Filter_Management_I::get_fake_stream(CompoMe::Function_stream_send &fs,
                                     CompoMe::Return_stream_recv &rs) {
  Filter_Management_I_fake_stream *a =
      new Filter_Management_I_fake_stream(fs, rs);
  std::tuple<Filter_Management_I_fake_stream *, CompoMe::Fake_stream *,
             Filter_Management_I *>
      rr(a, a, a);
  return rr;
}

Filter_Management_I_fake_stream::Filter_Management_I_fake_stream(
    CompoMe::Function_stream_send &out, CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Filter_Management_I_fake_stream::~Filter_Management_I_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Filter_Management_I
// ////////////////////////////////////////////////

void Filter_Management_I_fake_stream::add(CompoMe::Log::Kind_e k) {
  this->get_o().start();
  this->get_o() << "add(" << k << ")";
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

void Filter_Management_I_fake_stream::del(CompoMe::Log::Kind_e k) {
  this->get_o().start();
  this->get_o() << "del(" << k << ")";
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

// INTERFACE get/set Filter_Management_I
// /////////////////////////////////////////////////

} // namespace Log

} // namespace CompoMe
