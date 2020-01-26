
#include "Interfaces/I1/I1.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I1/I1_caller.hpp"
#include "Interfaces/I1/I1_fake.hpp"

I1::I1() : c(nullptr) {}

I1::~I1() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I1::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Build_fake_F get_build_fake(I1 *t) { return I1::MyFake::Build_func; }