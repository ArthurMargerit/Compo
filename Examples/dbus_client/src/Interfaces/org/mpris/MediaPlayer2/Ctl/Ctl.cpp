
#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl.hpp"

namespace org {

namespace mpris {

namespace MediaPlayer2 {

Ctl::Ctl() : a_caller_stream(nullptr) {}

Ctl::~Ctl() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Ctl::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
