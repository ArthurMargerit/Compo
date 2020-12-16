

#include "Components/Car/Gates/controller_Locker_locker.hpp"
#include "Components/Car/Gates/controller.hpp"

namespace Car {

namespace Gates {

controller_Locker_locker::controller_Locker_locker(controller *comp)
    : composant(comp) {
  return;
}

//! Destructor
controller_Locker_locker::~controller_Locker_locker() noexcept { return; }

controller &controller_Locker_locker::get_c() const { return *this->composant; }

} // namespace Gates

} // namespace Car
