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

class Window_caller_stream;

class Window_fake_stream;
class Window_fake_dbus;

class Window : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<Window_fake_stream *, CompoMe::Fake_stream *, Window *>;
  using T_p_dbus =
      std::tuple<Window_fake_dbus *, CompoMe::Fake_dbus *, Window *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Window_fake_dbus *, CompoMe::Fake_dbus *, Window *>(
        nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Car::Gate::Window_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Window();

  //! Destructor
  virtual ~Window() noexcept;
  virtual void lock() = 0;
  virtual void unlock() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual ui8 get_percent() const = 0;
  virtual void set_percent(const ui8 &percent) = 0;

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace Gate

} // namespace Car

#include "Interfaces/Car/Gate/Window/Window_caller_stream.hpp"

#include "Interfaces/Car/Gate/Window/Window_fake_stream.hpp"
