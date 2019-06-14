
#include "Interfaces/I_t1/I_t1.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I_t1/I_t1_caller.hpp"
#include "Interfaces/I_t1/I_t1_fake.hpp"

I_t1::I_t1() : c(nullptr) {}

I_t1::~I_t1() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I_t1::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Build_fake_F get_build_fake(I_t1 *t) { return I_t1::MyFake::Build_func; }