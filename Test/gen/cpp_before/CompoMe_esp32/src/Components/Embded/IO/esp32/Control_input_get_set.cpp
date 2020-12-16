#include "Components/Embded/IO/esp32/Control_input.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

/////////////////////////////////////////////////////////////////////////////
//                                   PROVIDE                               //
/////////////////////////////////////////////////////////////////////////////

Control_input_Pin_in_control &Control_input::get_control() {
  return this->control;
}

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// pool_down
bool Control_input::get_pool_down() const { return this->pool_down; }

void Control_input::set_pool_down(const bool &pool_down) {
  this->pool_down = pool_down;
}

// pool_up
bool Control_input::get_pool_up() const { return this->pool_up; }

void Control_input::set_pool_up(const bool &pool_up) {
  this->pool_up = pool_up;
}

// pin_id
ui8 Control_input::get_pin_id() const { return this->pin_id; }

void Control_input::set_pin_id(const ui8 &pin_id) { this->pin_id = pin_id; }

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace esp32

} // namespace IO

} // namespace Embded
