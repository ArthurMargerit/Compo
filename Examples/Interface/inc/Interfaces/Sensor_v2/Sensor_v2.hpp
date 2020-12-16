#pragma once

#include "Data/file.hpp"

#include "Interfaces/Sensor/Sensor.hpp"

#include <functional>
#include <tuple>

namespace CompoMe {
class Caller_stream;
class Fake_stream;

class Caller_dbus;
class Fake_dbus;

class Function_dbus_send;
class Return_dbus_recv;

class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

class Sensor_v2_caller_stream;

class Sensor_v2_fake_stream;
class Sensor_v2_fake_dbus;

class Sensor_v2 : public Sensor {
public:
  using T_p_stream =
      std::tuple<Sensor_v2_fake_stream *, CompoMe::Fake_stream *, Sensor_v2 *>;
  using T_p_dbus =
      std::tuple<Sensor_v2_fake_dbus *, CompoMe::Fake_dbus *, Sensor_v2 *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Sensor_v2_fake_dbus *, CompoMe::Fake_dbus *,
                           Sensor_v2 *>(nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Sensor_v2_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Sensor_v2();

  //! Destructor
  virtual ~Sensor_v2() noexcept;
  virtual void add_offset(double offset) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

#include "Interfaces/Sensor_v2/Sensor_v2_caller_stream.hpp"

#include "Interfaces/Sensor_v2/Sensor_v2_fake_stream.hpp"
