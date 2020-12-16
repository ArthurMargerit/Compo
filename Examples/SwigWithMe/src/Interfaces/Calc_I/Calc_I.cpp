
#include "Interfaces//Calc_I/Calc_I.hpp"

Calc_I::Calc_I() : a_caller_stream(nullptr) {}

Calc_I::~Calc_I() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Calc_I::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}
