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

namespace Gate {

class Locker_caller_stream;

class Locker_fake_stream;
class Locker_fake_dbus;

class Locker : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<Locker_fake_stream *, CompoMe::Fake_stream *, Locker *>;
  using T_p_dbus =
      std::tuple<Locker_fake_dbus *, CompoMe::Fake_dbus *, Locker *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Locker_fake_dbus *, CompoMe::Fake_dbus *, Locker *>(
        nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Car::Gate::Locker_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Locker();

  //! Destructor
  virtual ~Locker() noexcept;
  virtual void open_window() = 0;
  virtual void close_window() = 0;
  virtual CompoMe::String state() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace Gate

} // namespace Car

#include "Interfaces/Car/Gate/Locker/Locker_caller_stream.hpp"

#include "Interfaces/Car/Gate/Locker/Locker_fake_stream.hpp"
