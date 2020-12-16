#include "Components/Embded/IO/esp32/Control_input.hpp"
#include "Components/Embded/IO/esp32/Control_input_Pin_in_control.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

// Pin_in ///////////////////////////////////////////////////////////////////
// get/set state
Embded::IO::Pin_State Control_input_Pin_in_control::get_state() const {

  return this->state;
}

void Control_input_Pin_in_control::set_state(
    const Embded::IO::Pin_State &state) {

  this->state = state;
}

} // namespace esp32

} // namespace IO

} // namespace Embded
