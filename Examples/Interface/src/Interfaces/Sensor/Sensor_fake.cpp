#include "Interfaces/Sensor/Sensor_fake.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

Sensor_fake::Sensor_fake(Function_stream_send &out, Return_stream_recv &in)
    : Fake(out, in) {}

Sensor_fake::~Sensor_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Sensor ////////////////////////////////////////////////

double Sensor_fake::get_value() {
  this->get_o().start();
  this->get_o() << "get_value("
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

  double ri = double();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

Range Sensor_fake::get_range() {
  this->get_o().start();
  this->get_o() << "get_range("
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

  Range ri = Range();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Sensor /////////////////////////////////////////////////
