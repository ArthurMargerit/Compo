
#include "Interfaces/I_t2/I_t2.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I_t2/I_t2_caller.hpp"
#include "Interfaces/I_t2/I_t2_fake.hpp"

I_t2::I_t2() : c(nullptr) {}

I_t2::~I_t2() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I_t2::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Build_fake_F get_build_fake(I_t2 *t) { return I_t2::MyFake::Build_func; }