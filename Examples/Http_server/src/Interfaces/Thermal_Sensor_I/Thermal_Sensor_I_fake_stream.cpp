#include "Interfaces/Thermal_Sensor_I/Thermal_Sensor_I_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

Thermal_Sensor_I::T_p_stream
Thermal_Sensor_I::get_fake_stream(CompoMe::Function_stream_send &fs,
                                  CompoMe::Return_stream_recv &rs) {
  Thermal_Sensor_I_fake_stream *a = new Thermal_Sensor_I_fake_stream(fs, rs);
  std::tuple<Thermal_Sensor_I_fake_stream *, CompoMe::Fake_stream *,
             Thermal_Sensor_I *>
      rr(a, a, a);
  return rr;
}

Thermal_Sensor_I_fake_stream::Thermal_Sensor_I_fake_stream(
    CompoMe::Function_stream_send &out, CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Thermal_Sensor_I_fake_stream::~Thermal_Sensor_I_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Thermal_Sensor_I
// ////////////////////////////////////////////////

double Thermal_Sensor_I_fake_stream::get_temperature() {
  this->get_o().start();
  this->get_o() << "get_temperature("
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

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Thermal_Sensor_I
// /////////////////////////////////////////////////
double Thermal_Sensor_I_fake_stream::get_ofset() const {
  this->get_o().start();
  this->get_o() << "get_ofset()";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real(); // throw inside;
  }

  double ret;
  this->get_i() >> ret;
  this->get_i().end();
  return ret;
}

void Thermal_Sensor_I_fake_stream::set_ofset(const double &ofset) {
  this->get_o().start();
  this->get_o() << "set_ofset(" << ofset << ")";
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
