#include "Interfaces/Return_dbus_send.hpp"

#include "Structs/Struct.hpp"

namespace CompoMe {

void export_struct(Return_dbus_send &s, Struct &e) {
  e.to_dbus(s.get_so(), s.get_ctx());
}

} // namespace CompoMe
