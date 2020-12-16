#include "Interfaces/Sensor_v2/Sensor_v2_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

Sensor_v2::T_p_stream
Sensor_v2::get_fake_stream(CompoMe::Function_stream_send &fs,
                           CompoMe::Return_stream_recv &rs) {
  Sensor_v2_fake_stream *a = new Sensor_v2_fake_stream(fs, rs);
  std::tuple<Sensor_v2_fake_stream *, CompoMe::Fake_stream *, Sensor_v2 *> rr(
      a, a, a);
  return rr;
}

Sensor_v2_fake_stream::Sensor_v2_fake_stream(CompoMe::Function_stream_send &out,
                                             CompoMe::Return_stream_recv &in)
    : Sensor_fake_stream(out, in) {}

Sensor_v2_fake_stream::~Sensor_v2_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Sensor //////////////////////////////////////

double Sensor_v2_fake_stream::get_value() {
  return Sensor_fake_stream::get_value();
}

Range Sensor_v2_fake_stream::get_range() {
  return Sensor_fake_stream::get_range();
}

// INTERFACE Function Sensor_v2 ////////////////////////////////////////////////

void Sensor_v2_fake_stream::add_offset(double offset) {
  this->get_o().start();
  this->get_o() << "add_offset(" << offset << ")";
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

// INTERFACE get/set Sensor ////////////////////////////////////////

// INTERFACE get/set Sensor_v2 /////////////////////////////////////////////////
