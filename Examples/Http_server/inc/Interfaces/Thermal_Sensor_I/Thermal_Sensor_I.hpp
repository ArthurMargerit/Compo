#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

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

class Thermal_Sensor_I_caller_stream;

class Thermal_Sensor_I_fake_stream;
class Thermal_Sensor_I_fake_dbus;

class Thermal_Sensor_I : public CompoMe::Interface {
public:
  using T_p_stream = std::tuple<Thermal_Sensor_I_fake_stream *,
                                CompoMe::Fake_stream *, Thermal_Sensor_I *>;
  using T_p_dbus = std::tuple<Thermal_Sensor_I_fake_dbus *,
                              CompoMe::Fake_dbus *, Thermal_Sensor_I *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Thermal_Sensor_I_fake_dbus *, CompoMe::Fake_dbus *,
                           Thermal_Sensor_I *>(nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Thermal_Sensor_I_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Thermal_Sensor_I();

  //! Destructor
  virtual ~Thermal_Sensor_I() noexcept;
  virtual double get_temperature() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual double get_ofset() const = 0;
  virtual void set_ofset(const double &ofset) = 0;

private:
  CompoMe::Caller_stream *a_caller_stream;
};

#include "Interfaces/Thermal_Sensor_I/Thermal_Sensor_I_caller_stream.hpp"

#include "Interfaces/Thermal_Sensor_I/Thermal_Sensor_I_fake_stream.hpp"
