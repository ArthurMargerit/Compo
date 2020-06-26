#include "Interfaces/Interface.hpp"

Interface::Interface() {}

Interface::~Interface() {}

Caller_stream *Interface::get_caller_stream() {
  return NULL;
}

Caller_dbus *Interface::get_dbus_adapter() {
  return NULL;
}
