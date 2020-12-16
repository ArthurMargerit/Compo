#include "Components/Embded/IO/esp32/Control_output.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

/////////////////////////////////////////////////////////////////////////////
//                                   PROVIDE                               //
/////////////////////////////////////////////////////////////////////////////

Control_output_Pin_out_control &Control_output::get_control() {
  return this->control;
}

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// pool_down
bool Control_output::get_pool_down() const { return this->pool_down; }

void Control_output::set_pool_down(const bool &pool_down) {
  this->pool_down = pool_down;
}

// pool_up
bool Control_output::get_pool_up() const { return this->pool_up; }

void Control_output::set_pool_up(const bool &pool_up) {
  this->pool_up = pool_up;
}

// pin_id
ui8 Control_output::get_pin_id() const { return this->pin_id; }

void Control_output::set_pin_id(const ui8 &pin_id) { this->pin_id = pin_id; }

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace esp32

} // namespace IO

} // namespace Embded
