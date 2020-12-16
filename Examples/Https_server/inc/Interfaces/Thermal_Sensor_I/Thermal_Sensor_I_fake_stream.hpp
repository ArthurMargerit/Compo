#pragma once

#include "Data/file.hpp"

#include "Interfaces/Thermal_Sensor_I/Thermal_Sensor_I.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

class Thermal_Sensor_I_fake_stream : public Thermal_Sensor_I,
                                     public CompoMe::Fake_stream {
public:
  // constructor
  Thermal_Sensor_I_fake_stream(CompoMe::Function_stream_send &out,
                               CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Thermal_Sensor_I_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Thermal_Sensor_I*>(new Thermal_Sensor_I_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual double get_temperature() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual double get_ofset() const override;
  virtual void set_ofset(const double &ofset) override;
};
