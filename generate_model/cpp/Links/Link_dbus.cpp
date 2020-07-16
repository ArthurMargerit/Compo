#include "Links/Link_dbus.hpp"
namespace CompoMe {

Caller_dbus &Link_dbus_in::get_caller(std::string p_node,
                                      std::string p_interface) {
  return *this->a_c[p_node][p_interface];
}

bool Link_dbus_in::connected(std::string p_node, std::string p_interface) {
  return this->a_c.find(p_node) != this->a_c.end() &&
         this->a_c[p_node].find(p_interface) != this->a_c[p_node].end();
}

void Link_dbus_in::set_in(std::string p_node, std::string p_interface,
                          Interface *to) {
  this->a_c[p_node][p_interface] = to->get_caller_dbus();
}

void Link_dbus_out::set_out(std::string p_dest, std::string p_path,
                            std::string p_interface, Require_helper &p_req) {

  T_DPI t = T_DPI(p_dest, p_path, p_interface);
  this->a_f[&p_req] = t;
  this->connect(p_req);
  return;
}

} // namespace CompoMe
