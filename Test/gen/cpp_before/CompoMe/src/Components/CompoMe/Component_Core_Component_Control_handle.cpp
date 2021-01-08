

#include "Components/CompoMe/Component_Core_Component_Control_handle.hpp"
#include "Components/CompoMe/Component_Core.hpp"

namespace CompoMe {

Component_Core_Component_Control_handle::
    Component_Core_Component_Control_handle(Component_Core *comp)
    : composant(comp) {
  return;
}

//! Destructor
Component_Core_Component_Control_handle::
    ~Component_Core_Component_Control_handle() noexcept {
  return;
}

Component_Core &Component_Core_Component_Control_handle::get_c() const {
  return *this->composant;
}

} // namespace CompoMe
