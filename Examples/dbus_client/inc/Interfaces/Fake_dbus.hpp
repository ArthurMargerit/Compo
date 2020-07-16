#pragma once

#include "Interfaces/Function_dbus_send.hpp"
#include "Interfaces/Return_dbus_recv.hpp"

namespace DBus {
class MessageAppendIterator;
class MessageIterator;
} // namespace DBus

namespace CompoMe {

class Fake_dbus {
public:
  Return_dbus_recv &get_i() const { return a_i; }
  Function_dbus_send &get_o() const { return a_o; }

  Fake_dbus(Function_dbus_send &out, Return_dbus_recv &in);
  virtual ~Fake_dbus();

private:
  Function_dbus_send &a_o;
  Return_dbus_recv &a_i;
};

} // namespace CompoMe