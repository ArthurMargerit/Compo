

#include "Components/Embded/IO/esp32/Control_input_Pin_in_control.hpp"
#include "Components/Embded/IO/esp32/Control_input.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

Control_input_Pin_in_control::Control_input_Pin_in_control(Control_input *comp)
    : composant(comp), state() {
  return;
}

//! Destructor
Control_input_Pin_in_control::~Control_input_Pin_in_control() noexcept {
  return;
}

Control_input &Control_input_Pin_in_control::get_c() const {
  return *this->composant;
}

} // namespace esp32

} // namespace IO

} // namespace Embded
