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

class Hello_I_caller_stream;

class Hello_I_fake_stream;
class Hello_I_fake_dbus;

class Hello_I : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<Hello_I_fake_stream *, CompoMe::Fake_stream *, Hello_I *>;
  using T_p_dbus =
      std::tuple<Hello_I_fake_dbus *, CompoMe::Fake_dbus *, Hello_I *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Hello_I_fake_dbus *, CompoMe::Fake_dbus *,
                           Hello_I *>(nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Hello_I_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Hello_I();

  //! Destructor
  virtual ~Hello_I() noexcept;
  virtual CompoMe::String hello(CompoMe::String who) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

#include "Interfaces/Hello_I/Hello_I_caller_stream.hpp"

#include "Interfaces/Hello_I/Hello_I_fake_stream.hpp"
