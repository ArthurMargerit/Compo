
#include "Interfaces/Car/Gate/Locker/Locker.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Car/Gate/Locker/Locker_caller.hpp"
#include "Interfaces/Car/Gate/Locker/Locker_fake.hpp"
#include "Interfaces/Fake.hpp"

namespace Car {

namespace Gate {

Locker::Locker() : c(nullptr) {}

Locker::~Locker() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Locker::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

// Build_fake_F get_build_fake(Car::Gate::Locker* t) {
//   return Car::Gate::Locker::MyFake::Build_func;
// }

} // namespace Gate

} // namespace Car
