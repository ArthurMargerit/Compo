#include "Interfaces/Fake_dbus.hpp"

Fake_dbus::Fake_dbus(Function_dbus_send& out, Return_dbus_recv& in): a_o(out), a_i(in)
{}

Fake_dbus::~Fake_dbus() {}
