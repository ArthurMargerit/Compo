#include "Links/Link_dbus.hpp"

Dbus_adapter &Link_dbus_in::get_caller(std::string p_node, std::string p_interface) {
  return *this->a_c[p_node][p_interface];
}

bool Link_dbus_in::connected(std::string p_node, std::string p_interface) {
  return this->a_c.find(p_node) != this->a_c.end() && this->a_c.find(p_node)->find(p_interface) != this->a_c.end();
}

void Link_dbus_in::set_in(std::string p_node, std::string p_interface, Interface *to) {
  this->a_c[p_node][p_interface] = to->get_dbus_adapter();
}
