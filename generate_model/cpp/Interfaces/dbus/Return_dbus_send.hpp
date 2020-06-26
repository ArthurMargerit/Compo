#pragma once

#include <odbus>

class Return_dbus_send {
public:
  virtual std::odbus &get_so() = 0;

  virtual void start() = 0;
  virtual void send() = 0;
};

template <typename T>
Return_dbus_send &operator<<(Return_dbus_send &s, const T &e) {
  s.get_so() << e;
  return s;
}
