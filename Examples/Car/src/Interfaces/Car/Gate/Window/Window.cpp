
#include "Interfaces/Car/Gate/Window/Window.hpp"

namespace Car {

namespace Gate {

Window::Window() : a_caller_stream(nullptr) {}

Window::~Window() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Window::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace Gate

} // namespace Car
