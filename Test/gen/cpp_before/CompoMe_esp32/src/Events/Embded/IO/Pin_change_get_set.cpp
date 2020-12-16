#include "Events/Embded/IO/Pin_change.hpp"

namespace Embded {

namespace IO {

// GET SET ////////////////////////////////////////////////////////////////////
// get/set pin_id
ui8 Pin_change::get_pin_id() const { return this->pin_id; }

void Pin_change::set_pin_id(const ui8 &p_pin_id) { this->pin_id = p_pin_id; }

ui8 &Pin_change::a_pin_id() { return this->pin_id; }
// get/set pin_value
Embded::IO::Pin_State Pin_change::get_pin_value() const {
  return this->pin_value;
}

void Pin_change::set_pin_value(const Embded::IO::Pin_State &p_pin_value) {
  this->pin_value = p_pin_value;
}

Embded::IO::Pin_State &Pin_change::a_pin_value() { return this->pin_value; }

} // namespace IO

} // namespace Embded
