#pragma once
#include <dbus-cxx.h>

class Function_dbus_recv {
public:
  virtual DBus::MessageIterator &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
};

template <typename T>
Function_dbus_recv &operator>>(Function_dbus_recv &s, T &e) {
  s.get_si() >> e;
  return s;
}
