#pragma once

#include "Data/file.hpp"

#include "Interfaces/Sensor_v2/Sensor_v2.hpp"

#include "Interfaces/Sensor/Sensor_fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

class Sensor_v2_fake_stream : public Sensor_v2, public Sensor_fake_stream {
public:
  // constructor
  Sensor_v2_fake_stream(CompoMe::Function_stream_send &out,
                        CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Sensor_v2_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Sensor_v2*>(new Sensor_v2_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  // INTERFACE Function Sensor //////////////////////////////////////

  virtual double get_value() override;

  virtual Range get_range() override;

  virtual void add_offset(double offset) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  // INTERFACE get/set Sensor ////////////////////////////////////////
};
