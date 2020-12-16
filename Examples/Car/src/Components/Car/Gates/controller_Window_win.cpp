

#include "Components/Car/Gates/controller_Window_win.hpp"
#include "Components/Car/Gates/controller.hpp"

namespace Car {

namespace Gates {

controller_Window_win::controller_Window_win(controller *comp)
    : composant(comp), percent() {
  return;
}

//! Destructor
controller_Window_win::~controller_Window_win() noexcept { return; }

controller &controller_Window_win::get_c() const { return *this->composant; }

} // namespace Gates

} // namespace Car
