
#include "Interfaces/I_t3/I_t3.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I_t3/I_t3_caller.hpp"
#include "Interfaces/I_t3/I_t3_fake.hpp"

I_t3::I_t3() : c(nullptr) {}

I_t3::~I_t3() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I_t3::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Build_fake_F get_build_fake(I_t3 *t) { return I_t3::MyFake::Build_func; }