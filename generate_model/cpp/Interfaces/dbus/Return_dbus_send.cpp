#include "Interfaces/Return_dbus_send.hpp"

void export_struct(Return_dbus_send &s, Struct &e) {
  e.to_stream(s.get_so(), s.get_ctx());
}
