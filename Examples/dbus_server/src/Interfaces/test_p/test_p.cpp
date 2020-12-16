
#include "Interfaces//test_p/test_p.hpp"

test_p::test_p() : a_caller_stream(nullptr), a_caller_dbus(nullptr) {}

test_p::~test_p() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }

  if (a_caller_dbus != nullptr) {
    delete a_caller_dbus;
  }
}

CompoMe::Caller_stream *test_p::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

CompoMe::Caller_dbus *test_p::get_caller_dbus() {
  if (a_caller_dbus == nullptr) {
    a_caller_dbus = new MyCallerDbus(*this);
  }
  return a_caller_dbus;
}
