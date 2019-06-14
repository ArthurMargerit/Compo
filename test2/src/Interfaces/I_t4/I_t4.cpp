
#include "Interfaces/I_t4/I_t4.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I_t4/I_t4_caller.hpp"
#include "Interfaces/I_t4/I_t4_fake.hpp"

I_t4::I_t4() : c(nullptr) {}

I_t4::~I_t4() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I_t4::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Build_fake_F get_build_fake(I_t4 *t) { return I_t4::MyFake::Build_func; }