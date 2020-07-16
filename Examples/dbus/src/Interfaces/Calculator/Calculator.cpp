
#include "Interfaces//Calculator/Calculator.hpp"

Calculator::Calculator() : a_caller_stream(nullptr), a_caller_dbus(nullptr) {}

Calculator::~Calculator() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }

  if (a_caller_dbus != nullptr) {
    delete a_caller_dbus;
  }
}

CompoMe::Caller_stream *Calculator::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

CompoMe::Caller_dbus *Calculator::get_caller_dbus() {
  if (a_caller_dbus == nullptr) {
    a_caller_dbus = new MyCallerDbus(*this);
  }
  return a_caller_dbus;
}
