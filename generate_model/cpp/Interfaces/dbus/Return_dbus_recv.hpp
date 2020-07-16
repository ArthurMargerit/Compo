#pragma once
#include <dbus-cxx.h>
namespace CompoMe {

class Struct;

class Return_dbus_recv {
public:
  virtual DBus::MessageIterator &get_si() = 0;

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
