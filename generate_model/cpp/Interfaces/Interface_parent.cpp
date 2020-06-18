#include "Interfaces/Interface.hpp"

Interface::Interface() {}

Interface::~Interface() {}

Build_fake_F build_fake(Interface *t) {
  std::cout << "ERROR the type of Interface t pointer need to be know"
            << "\n";
  return NULL;
}

Caller *Interface::get_caller() { return NULL; }
Dbus_adapter *Interface::get_dbus_adapter() { return NULL; }
