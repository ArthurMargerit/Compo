#pragma once

#include "Data/CompoMe_esp32.hpp"

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

namespace Embded {

namespace IO {

class Pin_in_caller_stream;

class Pin_in_fake_stream;
class Pin_in_fake_dbus;

class Pin_in : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<Pin_in_fake_stream *, CompoMe::Fake_stream *, Pin_in *>;
  using T_p_dbus =
      std::tuple<Pin_in_fake_dbus *, CompoMe::Fake_dbus *, Pin_in *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Pin_in_fake_dbus *, CompoMe::Fake_dbus *, Pin_in *>(
        nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Embded::IO::Pin_in_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Pin_in();

  //! Destructor
  virtual ~Pin_in() noexcept;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual Embded::IO::Pin_State get_state() const = 0;
  virtual void set_state(const Embded::IO::Pin_State &state) = 0;

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace IO

} // namespace Embded

#include "Interfaces/Embded/IO/Pin_in/Pin_in_caller_stream.hpp"

#include "Interfaces/Embded/IO/Pin_in/Pin_in_fake_stream.hpp"
