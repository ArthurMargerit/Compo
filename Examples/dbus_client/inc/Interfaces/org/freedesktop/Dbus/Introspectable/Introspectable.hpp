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

namespace freedesktop {

namespace Dbus {

class Introspectable_caller_stream;

class Introspectable_fake_stream;
class Introspectable_fake_dbus;

class Introspectable : public CompoMe::Interface {
public:
  using T_p_stream = std::tuple<Introspectable_fake_stream *,
                                CompoMe::Fake_stream *, Introspectable *>;
  using T_p_dbus = std::tuple<Introspectable_fake_dbus *, CompoMe::Fake_dbus *,
                              Introspectable *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs);

  using MyCallerStream = org::freedesktop::Dbus::Introspectable_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Introspectable();

  //! Destructor
  virtual ~Introspectable() noexcept;
  virtual string Introspect() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace Dbus

} // namespace freedesktop

} // namespace org

#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_caller_stream.hpp"

#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_fake_stream.hpp"

#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_fake_dbus.hpp"
