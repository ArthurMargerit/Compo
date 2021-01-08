#include "Components/CompoMe/Component_Core.hpp"

namespace CompoMe {

/////////////////////////////////////////////////////////////////////////////
//                                   PROVIDE                               //
/////////////////////////////////////////////////////////////////////////////

Component_Core_Component_Control_handle &Component_Core::get_handle() {
  return this->handle;
}

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// name
CompoMe::String Component_Core::get_name() const { return this->name; }

void Component_Core::set_name(const CompoMe::String &name) {
  this->name = name;
}

// state
CompoMe::Component_state Component_Core::get_state() const {
  return this->state;
}

void Component_Core::set_state(const CompoMe::Component_state &state) {
  this->state = state;
}

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace CompoMe
