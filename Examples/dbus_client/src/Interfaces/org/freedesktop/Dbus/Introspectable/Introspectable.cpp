
#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable.hpp"

namespace org {

namespace freedesktop {

namespace Dbus {

Introspectable::Introspectable() : a_caller_stream(nullptr) {}

Introspectable::~Introspectable() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Introspectable::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace Dbus

} // namespace freedesktop

} // namespace org
