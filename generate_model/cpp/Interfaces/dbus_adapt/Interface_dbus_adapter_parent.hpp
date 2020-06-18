#pragma once

#include <dbus-cxx.h>
#include <string>
#include <sstream>

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
