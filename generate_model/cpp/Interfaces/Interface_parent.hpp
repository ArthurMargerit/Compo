#pragma once

#include <functional>
#include <iostream>
#include <memory>

class Caller_stream;
class Caller_dbus;

class Interface {
public:
  Interface();
  virtual ~Interface();
  virtual Caller_stream* get_caller_stream();
  virtual Caller_dbus* get_dbus_adapter();
  virtual bool is_fake() { return false; };
};
