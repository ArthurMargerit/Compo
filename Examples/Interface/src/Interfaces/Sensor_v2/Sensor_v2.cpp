
#include "Interfaces//Sensor_v2/Sensor_v2.hpp"

Sensor_v2::Sensor_v2() : a_caller_stream(nullptr) {}

Sensor_v2::~Sensor_v2() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Sensor_v2::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}
