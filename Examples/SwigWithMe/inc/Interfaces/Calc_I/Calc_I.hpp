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

class Calc_I_caller_stream;

class Calc_I_fake_stream;
class Calc_I_fake_dbus;

class Calc_I : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<Calc_I_fake_stream *, CompoMe::Fake_stream *, Calc_I *>;
  using T_p_dbus =
      std::tuple<Calc_I_fake_dbus *, CompoMe::Fake_dbus *, Calc_I *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Calc_I_fake_dbus *, CompoMe::Fake_dbus *, Calc_I *>(
        nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Calc_I_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Calc_I();

  //! Destructor
  virtual ~Calc_I() noexcept;
  virtual double add(double a, double b) = 0;
  virtual double sub(double a, double b) = 0;
  virtual double time(double a, double b) = 0;
  virtual double div(double a, double b) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

#include "Interfaces/Calc_I/Calc_I_caller_stream.hpp"

#include "Interfaces/Calc_I/Calc_I_fake_stream.hpp"
