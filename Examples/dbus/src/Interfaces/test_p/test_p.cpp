
#include "Interfaces//test_p/test_p.hpp"
#include "Interfaces//test_p/test_p_fake.hpp"

#include "Interfaces//test_p/test_p_caller.hpp"
#include "Interfaces//test_p/test_p_dbus_adapter.hpp"

test_p::test_p() : c(nullptr), c_dbus(nullptr) {}

test_p::~test_p() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *test_p::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Dbus_adapter *test_p::get_dbus_adapter() {
  if (c_dbus == nullptr) {
    c_dbus = new MyDbus_adapter(*this);
  }

  return c_dbus;
}

// Build_fake_F get_build_fake(test_p* t) {
//   return test_p::MyFake::Build_func;
// }
