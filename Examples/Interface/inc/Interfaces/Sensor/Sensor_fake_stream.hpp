#pragma once

#include "Data/file.hpp"

#include "Interfaces/Sensor/Sensor.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

class Sensor_fake_stream : public Sensor, public CompoMe::Fake_stream {
public:
  // constructor
  Sensor_fake_stream(CompoMe::Function_stream_send &out,
                     CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Sensor_fake_stream() noexcept;

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
