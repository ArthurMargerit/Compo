
#include "Interfaces/Ia/Ia.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Ia/Ia_caller.hpp"
#include "Interfaces/Ia/Ia_fake.hpp"

Ia::Ia() : c(nullptr) {}

Ia::~Ia() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Ia::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

Build_fake_F get_build_fake(Ia *t) { return Ia::MyFake::Build_func; }