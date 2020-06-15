
#include "Interfaces//Sensor/Sensor.hpp"
#include "Interfaces//Sensor/Sensor_caller.hpp"
#include "Interfaces//Sensor/Sensor_fake.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"

Sensor::Sensor() : c(nullptr) {}

Sensor::~Sensor() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Sensor::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

// Build_fake_F get_build_fake(Sensor* t) {
//   return Sensor::MyFake::Build_func;
// }
