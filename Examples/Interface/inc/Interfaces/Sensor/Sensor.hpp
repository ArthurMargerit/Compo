#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

#include "Structs/Range.hpp"

#include <functional>
#include <tuple>

namespace CompoMe {
class Caller_stream;
class Fake_stream;

class Caller_dbus;
class Fake_dbus;

class Caller_json;
class Fake_json;

class Function_dbus_send;
class Return_dbus_recv;

class Function_json_send;
class Return_json_recv;

class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

class Sensor_caller_stream;

class Sensor_fake_stream;
class Sensor_fake_dbus;
class Sensor_fake_json;

class Sensor : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<Sensor_fake_stream *, CompoMe::Fake_stream *, Sensor *>;
  using T_p_dbus =
      std::tuple<Sensor_fake_dbus *, CompoMe::Fake_dbus *, Sensor *>;
  using T_p_json =
      std::tuple<Sensor_fake_json *, CompoMe::Fake_json *, Sensor *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Sensor_fake_dbus *, CompoMe::Fake_dbus *, Sensor *>(
        nullptr, nullptr, nullptr);
  }

  static T_p_json get_fake_json(CompoMe::Function_json_send &fs,
                                CompoMe::Return_json_recv &rs) {
    return std::make_tuple<Sensor_fake_json *, CompoMe::Fake_json *, Sensor *>(
        nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Sensor_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Sensor();

  //! Destructor
  virtual ~Sensor() noexcept;
  virtual double get_value() = 0;
  virtual Range get_range() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

#include "Interfaces/Sensor/Sensor_caller_stream.hpp"

#include "Interfaces/Sensor/Sensor_fake_stream.hpp"
