#include "Components/Embded/IO/esp32/Control_output.hpp"
#include "Components/Embded/IO/esp32/Control_output_Pin_out_control.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

void Control_output_Pin_out_control::on() {
  this->set(PIN_STATE_UP);
  return;
}
void Control_output_Pin_out_control::off() {
  this->set(PIN_STATE_DOWN);
  return;
}

void Control_output_Pin_out_control::set(Embded::IO::Pin_State ps) {
  this->get_c().set((ps==PIN_STATE_UP)?1:0);
  return;
}

void Control_output_Pin_out_control::switch_v() {
  this->set((this->get_state() == PIN_STATE_UP)? PIN_STATE_DOWN:PIN_STATE_UP);
  return;
}

} // namespace esp32

} // namespace IO

} // namespace Embded
