#include "Interfaces/Interface.hpp"

Interface::Interface() {}

Interface::~Interface() {}

Caller_stream *Interface::get_caller_stream() {
  return nullptr;
}

Caller_dbus *Interface::get_caller_dbus() {
  return nullptr;
}
