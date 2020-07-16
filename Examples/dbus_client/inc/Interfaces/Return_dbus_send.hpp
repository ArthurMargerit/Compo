#pragma once
#include <dbus-cxx.h>

namespace CompoMe {
class Struct;

class Serialization_context_export;

class Return_dbus_send {
public:
  virtual DBus::MessageAppendIterator &get_so() = 0;

  virtual Serialization_context_export &get_ctx() = 0;

  virtual void start() = 0;
  virtual void send() = 0;
};

void export_struct(Return_dbus_send &s, Struct &e);
} // namespace CompoMe

template <typename T>
CompoMe::Return_dbus_send &operator<<(CompoMe::Return_dbus_send &s,
                                      const T &e) {
  s.get_so() << e;
  return s;
}