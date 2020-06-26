#pragma once
#include <string>

#include <dbus-cxx.h>

#include <sstream>

#include "Serialization_context.hpp"

class Dbus_adapter {
public:
  Dbus_adapter();
  virtual ~Dbus_adapter();

  virtual bool call(DBus::CallMessage::pointer msg,
                    DBus::ReturnMessage::pointer reply) = 0;

  virtual bool call(std::string &name_function, DBus::CallMessage::pointer msg,
                    DBus::ReturnMessage::pointer reply) = 0;

  virtual void introspection(std::stringstream& ss) = 0;
};

namespace DBus {

DBus::Message::iterator& operator<<(DBus::Message::iterator& is, const Serializable_Item& c);
DBus::Message::iterator& operator>>(DBus::Message::iterator& is, Serializable_Item& c);

}
