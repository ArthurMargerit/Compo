#pragma once

#include "Data/file.hpp"

#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable.hpp"

#include "Interfaces/Fake_dbus.hpp"

// class Function_stream_send;
// class Return_stream_recv;

namespace org {

namespace freedesktop {

namespace Dbus {

class Introspectable_fake_dbus : public org::freedesktop::Dbus::Introspectable,
                                 public CompoMe::Fake_dbus {
public:
  // constructor
  Introspectable_fake_dbus(CompoMe::Function_dbus_send &out,
                           CompoMe::Return_dbus_recv &in);

  //! Destructor
  virtual ~Introspectable_fake_dbus() noexcept;

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual CompoMe::String Introspect() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace Dbus

} // namespace freedesktop

} // namespace org
