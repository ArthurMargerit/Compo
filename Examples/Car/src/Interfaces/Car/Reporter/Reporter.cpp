
#include "Interfaces/Car/Reporter/Reporter.hpp"

namespace Car {

Reporter::Reporter() : a_caller_stream(nullptr) {}

Reporter::~Reporter() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Reporter::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace Car
