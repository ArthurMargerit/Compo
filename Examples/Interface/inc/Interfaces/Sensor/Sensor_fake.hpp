#pragma once

#include "Data/file.hpp"

#include "Interfaces/Sensor/Sensor.hpp"

#include "Interfaces/Fake.hpp"

class Function_stream_send;
class Return_stream_recv;

class Sensor_fake : public Sensor, public Fake {
public:
  // constructor
  Sensor_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~Sensor_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Sensor*>(new Sensor_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual double get_value() override;

  virtual Range get_range() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
