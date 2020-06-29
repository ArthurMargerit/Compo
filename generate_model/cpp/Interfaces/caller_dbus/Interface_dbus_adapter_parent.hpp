#pragma once
#include <string>

#include <dbus-cxx.h>

#include <sstream>

#include "Serialization_context.hpp"
class Function_dbus_recv;
class Return_dbus_send;

class Caller_dbus {
public:
  Caller_dbus();
  virtual ~Caller_dbus();

  virtual bool call(Function_dbus_recv &,
                    Return_dbus_send &) = 0;

  virtual bool call(std::string &name_function,
                    Function_dbus_recv &,
                    Return_dbus_send &) = 0;

  virtual void introspection(std::ostream& ss) = 0;
};

// namespace DBus {
// DBus::Message::iterator& operator<<(DBus::Message::iterator& is, const Serializable_Item& c);
// DBus::Message::iterator& operator>>(DBus::Message::iterator& is, Serializable_Item& c);
// }
