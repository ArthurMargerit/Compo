
#include "Interfaces//Calculator/Calculator.hpp"
#include "Interfaces//Calculator/Calculator_fake.hpp"

#include "Interfaces//Calculator/Calculator_caller.hpp"
#include "Interfaces//Calculator/Calculator_dbus_adapter.hpp"

Calculator::Calculator() : c(nullptr), c_dbus(nullptr) {}

Calculator::~Calculator() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Calculator::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Dbus_adapter *Calculator::get_dbus_adapter() {
  if (c_dbus == nullptr) {
    c_dbus = new MyDbus_adapter(*this);
  }

  return c_dbus;
}

// Build_fake_F get_build_fake(Calculator* t) {
//   return Calculator::MyFake::Build_func;
// }