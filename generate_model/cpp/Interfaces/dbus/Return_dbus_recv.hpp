#pragma once
#include <dbus/dbus.h>

namespace CompoMe {

class Struct;

class Return_dbus_recv {
public:
  virtual DBusMessageIter &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
};

} // namespace CompoMe

template <typename T>
CompoMe::Return_dbus_recv &operator>>(CompoMe::Return_dbus_recv &s, T &e) {
  s.get_si() >> e;
  return s;
}

CompoMe::Return_dbus_recv &operator>>(CompoMe::Return_dbus_recv &s, CompoMe::Struct &e);
