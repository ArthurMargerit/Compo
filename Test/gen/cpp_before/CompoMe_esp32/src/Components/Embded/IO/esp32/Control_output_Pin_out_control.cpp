

#include "Components/Embded/IO/esp32/Control_output_Pin_out_control.hpp"
#include "Components/Embded/IO/esp32/Control_output.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

Control_output_Pin_out_control::Control_output_Pin_out_control(
    Control_output *comp)
    : composant(comp), state() {
  return;
}

//! Destructor
Control_output_Pin_out_control::~Control_output_Pin_out_control() noexcept {
  return;
}

Control_output &Control_output_Pin_out_control::get_c() const {
  return *this->composant;
}

} // namespace esp32

} // namespace IO

} // namespace Embded
