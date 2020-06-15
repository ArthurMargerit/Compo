#include "Interfaces/Information/Information_fake.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

Information_fake::Information_fake(Function_stream_send &out,
                                   Return_stream_recv &in)
    : Fake(out, in) {}

Information_fake::~Information_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Information
// ////////////////////////////////////////////////

string Information_fake::get_name() {
  this->get_o().start();
  this->get_o() << "get_name("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  string ri = string();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

string Information_fake::get_type() {
  this->get_o().start();
  this->get_o() << "get_type("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  string ri = string();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

string Information_fake::get_location() {
  this->get_o().start();
  this->get_o() << "get_location("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  string ri = string();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Information
// /////////////////////////////////////////////////
