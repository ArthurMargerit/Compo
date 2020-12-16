
#include "Interfaces//Hello_I/Hello_I.hpp"

Hello_I::Hello_I() : a_caller_stream(nullptr) {}

Hello_I::~Hello_I() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Hello_I::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}
