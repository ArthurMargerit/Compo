#include "Components/Car/Gates/controller.hpp"
#include "Components/Car/Gates/controller_Window_win.hpp"

namespace Car {

namespace Gates {

// Window ///////////////////////////////////////////////////////////////////
// get/set percent
ui8 controller_Window_win::get_percent() const { return this->percent; }

void controller_Window_win::set_percent(const ui8 &percent) {

  this->percent = percent;
}

} // namespace Gates

} // namespace Car
