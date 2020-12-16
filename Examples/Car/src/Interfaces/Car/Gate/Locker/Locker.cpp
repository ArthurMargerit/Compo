
#include "Interfaces/Car/Gate/Locker/Locker.hpp"

namespace Car {

namespace Gate {

Locker::Locker() : a_caller_stream(nullptr) {}

Locker::~Locker() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Locker::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace Gate

} // namespace Car
