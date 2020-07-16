#pragma once

#include "Data/file.hpp"

#include "Interfaces/test_p/test_p.hpp"

#include "Structs/S1.hpp"

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

class test_caller_stream;

class test_caller_dbus;

class test_fake_stream;
class test_fake_dbus;

class test : public test_p {
public:
  using T_p_stream =
      std::tuple<test_fake_stream *, CompoMe::Fake_stream *, test *>;
  using T_p_dbus = std::tuple<test_fake_dbus *, CompoMe::Fake_dbus *, test *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<test_fake_dbus *, CompoMe::Fake_dbus *, test *>(
        nullptr, nullptr, nullptr);
  }

  using MyCallerStream = test_caller_stream;

  using MyCallerDbus = test_caller_dbus;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  CompoMe::Caller_dbus *get_caller_dbus() override;

  //! Default constructor
  test();

  //! Destructor
  virtual ~test() noexcept;
  virtual void f7(u8 a) = 0;
  virtual void f8(u16 a) = 0;
  virtual void f9(u32 a) = 0;
  virtual void f10(u64 a) = 0;
  virtual void f11(S1 a) = 0;
  virtual S1 f12() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual i32 get_a() const = 0;
  virtual void set_a(const i32 &a) = 0;
  virtual i64 get_b() const = 0;
  virtual void set_b(const i64 &b) = 0;

private:
  CompoMe::Caller_stream *a_caller_stream;

  CompoMe::Caller_dbus *a_caller_dbus;
};

#include "Interfaces/test/test_caller_stream.hpp"

#include "Interfaces/test/test_caller_dbus.hpp"

#include "Interfaces/test/test_fake_stream.hpp"
