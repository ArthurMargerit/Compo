#pragma once
#include <dbus-cxx.h>

#include "Data/Struct.hpp"

class Serialization_context_export;

class Return_dbus_send {
public:
  virtual DBus::MessageAppendIterator &get_so() = 0;

  virtual Serialization_context_export &get_ctx() = 0;

  virtual void start() = 0;
  virtual void send() = 0;
};

void export_struct(Return_dbus_send &s, Struct &e);

template <typename T>
Return_dbus_send &operator<<(Return_dbus_send &s, const T &e) {
  s.get_so() << e;
  return s;
}
