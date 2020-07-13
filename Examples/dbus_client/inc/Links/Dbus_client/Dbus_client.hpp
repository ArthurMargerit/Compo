#pragma once

#include "Links/Link.hpp"
#include "Links/Link_dbus.hpp"

class Function_stream;
class Return_stream;
class Interface;

#include "Data/dbus.hpp"

#include <functional>

class Dbus_client : public Link, public Link_dbus_out {
public:
  Dbus_client();
  virtual ~Dbus_client();

  void step() override;
  void connect() override;
  void disconnect() override;

  void connect(Require_helper &p_i) override;
  void disconnect(Require_helper & p_i) override;

  // Get and set /////////////////////////////////////////////////////////////

  virtual string get_object_name() const;
  virtual void set_object_name(const string object_name);
  virtual i32 get_timeout() const;
  virtual void set_timeout(const i32 timeout);

private:
  // DATA ////////////////////////////////////////////////////////////////////

  string object_name;
  i32 timeout;
  std::map<Require_helper *, Function_dbus_send *> function_dbus;
  DBus::Connection::pointer co;
  DBus::Dispatcher::pointer di;
};
