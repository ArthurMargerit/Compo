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

class test_p_caller_stream;

class test_p_caller_dbus;

class test_p_fake_stream;
class test_p_fake_dbus;

class test_p : public CompoMe::Interface {
public:
  using T_p_stream =
      std::tuple<test_p_fake_stream *, CompoMe::Fake_stream *, test_p *>;
  using T_p_dbus =
      std::tuple<test_p_fake_dbus *, CompoMe::Fake_dbus *, test_p *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<test_p_fake_dbus *, CompoMe::Fake_dbus *, test_p *>(
        nullptr, nullptr, nullptr);
  }

  using MyCallerStream = test_p_caller_stream;

  using MyCallerDbus = test_p_caller_dbus;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  CompoMe::Caller_dbus *get_caller_dbus() override;

  //! Default constructor
  test_p();

  //! Destructor
  virtual ~test_p() noexcept;
  virtual void f0() = 0;
  virtual void f1(double a) = 0;
  virtual void f2(i8 a) = 0;
  virtual void f3(i16 a) = 0;
  virtual void f5(i32 a) = 0;
  virtual void f6(i64 a) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;

  CompoMe::Caller_dbus *a_caller_dbus;
};

#include "Interfaces/test_p/test_p_caller_stream.hpp"

#include "Interfaces/test_p/test_p_caller_dbus.hpp"

#include "Interfaces/test_p/test_p_fake_stream.hpp"
