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

class Information_I_caller_stream;

class Information_I_fake_stream;
class Information_I_fake_dbus;

class Information_I : public CompoMe::Interface {
public:
  using T_p_stream = std::tuple<Information_I_fake_stream *,
                                CompoMe::Fake_stream *, Information_I *>;
  using T_p_dbus = std::tuple<Information_I_fake_dbus *, CompoMe::Fake_dbus *,
                              Information_I *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Information_I_fake_dbus *, CompoMe::Fake_dbus *,
                           Information_I *>(nullptr, nullptr, nullptr);
  }

  using MyCallerStream = Information_I_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Information_I();

  //! Destructor
  virtual ~Information_I() noexcept;
  virtual CompoMe::String get_name() = 0;
  virtual CompoMe::String get_type() = 0;
  virtual CompoMe::String get_location() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

#include "Interfaces/Information_I/Information_I_caller_stream.hpp"

#include "Interfaces/Information_I/Information_I_fake_stream.hpp"
