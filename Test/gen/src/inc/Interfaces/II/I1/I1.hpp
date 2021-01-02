#pragma once

#include "Data/code.hpp"

#include "Interfaces/Interface.hpp"

#include "Structs/S/S2.hpp"

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

namespace II {

class I1_caller_stream;

class I1_fake_stream;
class I1_fake_dbus;

class I1 : public CompoMe::Interface {
public:
  using T_p_stream = std::tuple<I1_fake_stream *, CompoMe::Fake_stream *, I1 *>;
  using T_p_dbus = std::tuple<I1_fake_dbus *, CompoMe::Fake_dbus *, I1 *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<I1_fake_dbus *, CompoMe::Fake_dbus *, I1 *>(
        nullptr, nullptr, nullptr);
  }

  using MyCallerStream = II::I1_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  I1();

  //! Destructor
  virtual ~I1() noexcept;
  virtual B::i f1() = 0;
  virtual B::i f2(B::i a, B::i b) = 0;
  virtual B::i f3(S1 a, S::S2 b) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual B::i get_v() const = 0;
  virtual void set_v(const B::i &v) = 0;

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace II

#include "Interfaces/II/I1/I1_caller_stream.hpp"

#include "Interfaces/II/I1/I1_fake_stream.hpp"
