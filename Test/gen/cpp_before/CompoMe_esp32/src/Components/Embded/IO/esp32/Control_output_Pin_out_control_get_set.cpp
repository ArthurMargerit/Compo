#include "Components/Embded/IO/esp32/Control_output.hpp"
#include "Components/Embded/IO/esp32/Control_output_Pin_out_control.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

// Pin_out ///////////////////////////////////////////////////////////////////
// get/set state
Embded::IO::Pin_State Control_output_Pin_out_control::get_state() const {

  return this->state;
}

void Control_output_Pin_out_control::set_state(
    const Embded::IO::Pin_State &state) {

  this->state = state;
}

} // namespace esp32

} // namespace IO

} // namespace Embded
