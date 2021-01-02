
#include "Interfaces/II/I1/I1.hpp"

namespace II {

I1::I1() : a_caller_stream(nullptr) {}

I1::~I1() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *I1::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace II
