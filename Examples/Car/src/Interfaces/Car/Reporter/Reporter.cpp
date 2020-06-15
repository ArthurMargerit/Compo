
#include "Interfaces/Car/Reporter/Reporter.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Car/Reporter/Reporter_caller.hpp"
#include "Interfaces/Car/Reporter/Reporter_fake.hpp"
#include "Interfaces/Fake.hpp"

namespace Car {

Reporter::Reporter() : c(nullptr) {}

Reporter::~Reporter() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Reporter::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

// Build_fake_F get_build_fake(Car::Reporter* t) {
//   return Car::Reporter::MyFake::Build_func;
// }

} // namespace Car
