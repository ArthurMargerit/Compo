
#include "Interfaces//test/test.hpp"
#include "Interfaces//test/test_fake.hpp"

#include "Interfaces//test/test_caller.hpp"
#include "Interfaces//test/test_dbus_adapter.hpp"

test::test() : c(nullptr), c_dbus(nullptr) {}

test::~test() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *test::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Dbus_adapter *test::get_dbus_adapter() {
  if (c_dbus == nullptr) {
    c_dbus = new MyDbus_adapter(*this);
  }

  return c_dbus;
}

// Build_fake_F get_build_fake(test* t) {
//   return test::MyFake::Build_func;
// }
