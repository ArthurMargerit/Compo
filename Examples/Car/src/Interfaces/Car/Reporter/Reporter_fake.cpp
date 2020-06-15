#include "Interfaces/Car/Reporter/Reporter_fake.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

namespace Car {

Reporter_fake::Reporter_fake(Function_stream_send &out, Return_stream_recv &in)
    : Fake(out, in) {}

Reporter_fake::~Reporter_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Reporter ////////////////////////////////////////////////

void Reporter_fake::send_err(int err_code, string message) {
  this->get_o().start();
  this->get_o() << "send_err(" << err_code << "," << message << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void Reporter_fake::send_info(int info_code, string message) {
  this->get_o().start();
  this->get_o() << "send_info(" << info_code << "," << message << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
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
