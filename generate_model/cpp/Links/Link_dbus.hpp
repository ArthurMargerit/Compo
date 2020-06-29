#pragma once

#include "Interfaces/Interface.hpp"
#include "Interfaces/Caller_dbus.hpp"

#include <map>
#include <string>

class Link_dbus_in {
protected:
  std::map<std::string,std::map<std::string, Caller_dbus*> > a_c;

public:
  Caller_dbus &get_caller(std::string p_node, std::string p_interface);
  bool connected(std::string p_node, std::string p_interface);
  virtual void set_in(std::string p_node, std::string p_interface, Interface *to);
};
