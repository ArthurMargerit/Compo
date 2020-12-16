#include "Events/Embded/IO/Pin_change.hpp"

#include <istream>
#include <ostream>
#include <sstream>

namespace Embded {

namespace IO {

Pin_change::Pin_change() : Pin_change(ui8(), Embded::IO::Pin_State()) {}

Pin_change::Pin_change(ui8 p_pin_id, Embded::IO::Pin_State p_pin_value)
    : CompoMe::Event(), pin_id(p_pin_id)

      ,
      pin_value(p_pin_value) {}

Pin_change::~Pin_change() {}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool Pin_change::operator==(const Embded::IO::Pin_change &other) const {
  return true

         && this->pin_id == other.pin_id

         && this->pin_value == other.pin_value;
}

bool Pin_change::operator!=(const Embded::IO::Pin_change &other) const {
  return !(*this == other);
}

} // namespace IO

} // namespace Embded
