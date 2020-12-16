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

namespace Car {

class Reporter_caller_stream;

class Reporter_fake_stream;
class Reporter_fake_dbus;

class Reporter : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<Reporter_fake_stream *, CompoMe::Fake_stream *, Reporter *>;
  using T_p_dbus =
      std::tuple<Reporter_fake_dbus *, CompoMe::Fake_dbus *, Reporter *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Reporter_fake_dbus *, CompoMe::Fake_dbus *,
                           Reporter *>(nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Car::Reporter_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Reporter();

  //! Destructor
  virtual ~Reporter() noexcept;
  virtual void send_err(i32 err_code, CompoMe::String message) = 0;
  virtual void send_info(i32 info_code, CompoMe::String message) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace Car

#include "Interfaces/Car/Reporter/Reporter_caller_stream.hpp"

#include "Interfaces/Car/Reporter/Reporter_fake_stream.hpp"
