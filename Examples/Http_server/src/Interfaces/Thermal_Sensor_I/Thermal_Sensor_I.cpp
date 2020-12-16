
#include "Interfaces//Thermal_Sensor_I/Thermal_Sensor_I.hpp"

Thermal_Sensor_I::Thermal_Sensor_I() : a_caller_stream(nullptr) {}

Thermal_Sensor_I::~Thermal_Sensor_I() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Thermal_Sensor_I::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}
