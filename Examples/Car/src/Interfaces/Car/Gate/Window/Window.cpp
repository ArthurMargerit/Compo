
#include "Interfaces/Car/Gate/Window/Window.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Car/Gate/Window/Window_caller.hpp"
#include "Interfaces/Car/Gate/Window/Window_fake.hpp"
#include "Interfaces/Fake.hpp"

namespace Car {

namespace Gate {

Window::Window() : c(nullptr) {}

Window::~Window() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Window::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

// Build_fake_F get_build_fake(Car::Gate::Window* t) {
//   return Car::Gate::Window::MyFake::Build_func;
// }

} // namespace Gate

} // namespace Car
