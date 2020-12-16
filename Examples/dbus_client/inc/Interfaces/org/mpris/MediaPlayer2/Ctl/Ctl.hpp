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

namespace org {

namespace mpris {

namespace MediaPlayer2 {

class Ctl_caller_stream;

class Ctl_fake_stream;
class Ctl_fake_dbus;

class Ctl : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<Ctl_fake_stream *, CompoMe::Fake_stream *, Ctl *>;
  using T_p_dbus = std::tuple<Ctl_fake_dbus *, CompoMe::Fake_dbus *, Ctl *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs);

  using MyCallerStream = org::mpris::MediaPlayer2::Ctl_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Ctl();

  //! Destructor
  virtual ~Ctl() noexcept;
  virtual void Quit() = 0;
  virtual void Raise() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org

#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_caller_stream.hpp"

#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_fake_stream.hpp"

#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl_fake_dbus.hpp"
