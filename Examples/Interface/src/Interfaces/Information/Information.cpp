
#include "Interfaces//Information/Information.hpp"
#include "Interfaces//Information/Information_caller.hpp"
#include "Interfaces//Information/Information_fake.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"

Information::Information() : c(nullptr) {}

Information::~Information() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Information::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

// Build_fake_F get_build_fake(Information* t) {
//   return Information::MyFake::Build_func;
// }
