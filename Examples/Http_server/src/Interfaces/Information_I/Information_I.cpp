
#include "Interfaces//Information_I/Information_I.hpp"

Information_I::Information_I() : a_caller_stream(nullptr) {}

Information_I::~Information_I() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Information_I::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}
