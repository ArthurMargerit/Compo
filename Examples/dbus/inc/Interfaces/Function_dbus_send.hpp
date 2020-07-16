#pragma once
#include <dbus-cxx.h>

namespace CompoMe {
class Struct;

class Function_dbus_send {
public:
  virtual DBus::MessageAppendIterator &get_so() = 0;
  virtual void set_function(std::string str) = 0;
  virtual void start() = 0;
  virtual void send() = 0;
};

} // namespace CompoMe

template <typename T>
CompoMe::Function_dbus_send &operator<<(CompoMe::Function_dbus_send &s,
                                        const T &e) {
  s.get_so() << e;
  return s;
}

CompoMe::Function_dbus_send &operator>>(CompoMe::Function_dbus_send &s,
                                        CompoMe::Struct &e);