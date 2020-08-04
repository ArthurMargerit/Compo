#include "Interfaces/Sensor/Sensor_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

Sensor::T_p_stream Sensor::get_fake_stream(CompoMe::Function_stream_send &fs,
                                           CompoMe::Return_stream_recv &rs) {
  Sensor_fake_stream *a = new Sensor_fake_stream(fs, rs);
  std::tuple<Sensor_fake_stream *, CompoMe::Fake_stream *, Sensor *> rr(a, a,
                                                                        a);
  return rr;
}

Sensor_fake_stream::Sensor_fake_stream(CompoMe::Function_stream_send &out,
                                       CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Sensor_fake_stream::~Sensor_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Sensor ////////////////////////////////////////////////

double Sensor_fake_stream::get_value() {
  this->get_o().start();
  this->get_o() << "get_value("
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

  double ri = double();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

Range Sensor_fake_stream::get_range() {
  this->get_o().start();
  this->get_o() << "get_range("
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

  Range ri = Range();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Sensor /////////////////////////////////////////////////
