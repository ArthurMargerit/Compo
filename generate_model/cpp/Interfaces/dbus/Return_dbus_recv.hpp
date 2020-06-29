#pragma once
#include <dbus-cxx.h>

class Struct;

class Return_dbus_recv {
public:
  virtual DBus::MessageIterator &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
};

template <typename T>
Return_dbus_recv &operator>>(Return_dbus_recv &s, T &e) {
  s.get_si() >> e;
  return s;
}

Return_dbus_recv &operator>>(Return_dbus_recv &s, Struct& e);
