
#include "Interfaces//Sensor/Sensor.hpp"

Sensor::Sensor() : a_caller_stream(nullptr) {}

Sensor::~Sensor() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Sensor::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}
