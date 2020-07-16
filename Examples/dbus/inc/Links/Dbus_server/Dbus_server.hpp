#pragma once

#include "Links/Link.hpp"
#include "Links/Link_dbus.hpp"
#include "Data/dbus.hpp"
#include <functional>

class Dbus_server : public CompoMe::Link, public CompoMe::Link_dbus_in {
public:
  Dbus_server();
  virtual ~Dbus_server();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // Get and set /////////////////////////////////////////////////////////////

  virtual string get_object_name() const;
  virtual void set_object_name(const string object_name);

private:
  // DATA ////////////////////////////////////////////////////////////////////

  string object_name;

  DBus::Connection::pointer conn;
  void introspection(DBus::CallMessage::pointer msg,
                     DBus::ReturnMessage::pointer reply);
};
