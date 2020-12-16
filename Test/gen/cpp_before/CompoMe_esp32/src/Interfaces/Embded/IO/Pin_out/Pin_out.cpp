
#include "Interfaces/Embded/IO/Pin_out/Pin_out.hpp"

namespace Embded {

namespace IO {

Pin_out::Pin_out() : a_caller_stream(nullptr) {}

Pin_out::~Pin_out() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Pin_out::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace IO

} // namespace Embded
