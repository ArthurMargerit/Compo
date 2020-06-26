#include "Interfaces/Function_dbus_recv.hpp"

Function_dbus_recv &getline(Function_dbus_recv &is, std::string &str,
                              char delim) {
  std::getline(is.get_si(), str, delim);
  return is;
}
Function_dbus_recv &getline(Function_dbus_recv &is, std::string &str) {
  std::getline(is.get_si(), str, '\n');
  return is;
}
