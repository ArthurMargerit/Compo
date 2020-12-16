
#include "Interfaces/CompoMe/Log/Filter_Management_I/Filter_Management_I.hpp"

namespace CompoMe {

namespace Log {

Filter_Management_I::Filter_Management_I() : a_caller_stream(nullptr) {}

Filter_Management_I::~Filter_Management_I() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Filter_Management_I::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace Log

} // namespace CompoMe
