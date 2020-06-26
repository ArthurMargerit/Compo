
#include "Interfaces/Caller_dbus.hpp"

Caller_dbus::Caller_dbus() {}

Caller_dbus::~Caller_dbus() {}

// DBus::Message::iterator &operator<<(DBus::Message::iterator &is,
//                                     const std::string &c){
//   return is;
// }

// DBus::Message::iterator &operator<<(DBus::Message::iterator &is,
//                                     const Serializable_Item &c) {
//   is << c.to_string();
//   return is;
// }

// DBus::Message::iterator &operator>>(DBus::Message::iterator &is,
//                                     Serializable_Item &c) {
//   std::string ss;
//   is >> ss;

//   c.from_string(ss);
//   return is;
// }
