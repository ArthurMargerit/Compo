#pragma once

#include "Data/file.hpp"

#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace org {

namespace freedesktop {

namespace Dbus {

class Introspectable_fake_stream
    : public org::freedesktop::Dbus::Introspectable,
      public CompoMe::Fake_stream {
public:
  // constructor
  Introspectable_fake_stream(CompoMe::Function_stream_send &out,
                             CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Introspectable_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<org::freedesktop::Dbus::Introspectable*>(new
  //   org::freedesktop::Dbus::Introspectable_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual string Introspect() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace Dbus

} // namespace freedesktop

} // namespace org
