#pragma once

#include "Interfaces/Dbus_adapter.hpp"
#include "Interfaces/Interface.hpp"

#include <map>
#include <string>

class Link_dbus_in {
private:


public:
  std::map<std::string, std::map<std::string, Dbus_adapter *>> a_c;
  Dbus_adapter &get_caller(std::string p_node, std::string p_interface);
  bool connected(std::string p_node, std::string p_interface);
  virtual void set_in(std::string p_node, std::string p_interface,
                      Interface *to);
};
