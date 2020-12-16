#include "Interfaces/Car/Reporter/Reporter_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace Car {

Reporter::T_p_stream
Reporter::get_fake_stream(CompoMe::Function_stream_send &fs,
                          CompoMe::Return_stream_recv &rs) {
  Reporter_fake_stream *a = new Reporter_fake_stream(fs, rs);
  std::tuple<Reporter_fake_stream *, CompoMe::Fake_stream *, Reporter *> rr(
      a, a, a);
  return rr;
}

Reporter_fake_stream::Reporter_fake_stream(CompoMe::Function_stream_send &out,
                                           CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Reporter_fake_stream::~Reporter_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Reporter ////////////////////////////////////////////////

void Reporter_fake_stream::send_err(i32 err_code, CompoMe::String message) {
  this->get_o().start();
  this->get_o() << "send_err(" << err_code << "," << message << ")";
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

void Reporter_fake_stream::send_info(i32 info_code, CompoMe::String message) {
  this->get_o().start();
  this->get_o() << "send_info(" << info_code << "," << message << ")";
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

// INTERFACE get/set Reporter /////////////////////////////////////////////////

} // namespace Car
