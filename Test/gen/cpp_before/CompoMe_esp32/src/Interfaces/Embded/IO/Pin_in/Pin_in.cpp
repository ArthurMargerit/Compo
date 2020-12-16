
#include "Interfaces/Embded/IO/Pin_in/Pin_in.hpp"

namespace Embded {

namespace IO {

Pin_in::Pin_in() : a_caller_stream(nullptr) {}

Pin_in::~Pin_in() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Pin_in::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace IO

} // namespace Embded
