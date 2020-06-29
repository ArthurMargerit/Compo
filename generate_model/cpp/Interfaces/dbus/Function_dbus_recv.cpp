#include "Interfaces/Function_dbus_recv.hpp"

void import_struct(Function_dbus_recv &s, Struct &e) {
  e.from_stream(s.get_si(), s.get_ctx());
}
