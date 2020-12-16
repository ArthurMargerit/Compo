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

class Calculator_caller_stream;

class Calculator_caller_dbus;

class Calculator_fake_stream;
class Calculator_fake_dbus;

class Calculator : public CompoMe::Interface {
public:
  using T_p_stream = std::tuple<Calculator_fake_stream *,
                                CompoMe::Fake_stream *, Calculator *>;
  using T_p_dbus =
      std::tuple<Calculator_fake_dbus *, CompoMe::Fake_dbus *, Calculator *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Calculator_fake_dbus *, CompoMe::Fake_dbus *,
                           Calculator *>(nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Calculator_caller_stream;

  using MyCallerDbus = Calculator_caller_dbus;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  CompoMe::Caller_dbus *get_caller_dbus() override;

  //! Default constructor
  Calculator();

  //! Destructor
  virtual ~Calculator() noexcept;
  virtual double add(double a, double b) = 0;
  virtual double sub(double a, double b) = 0;
  virtual double time(double a, double b) = 0;
  virtual double div(double a, double b) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;

  CompoMe::Caller_dbus *a_caller_dbus;
};

#include "Interfaces/Calculator/Calculator_caller_stream.hpp"

#include "Interfaces/Calculator/Calculator_caller_dbus.hpp"

#include "Interfaces/Calculator/Calculator_fake_stream.hpp"
