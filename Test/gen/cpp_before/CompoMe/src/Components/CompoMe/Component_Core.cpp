
#include "Components/CompoMe/Component_Core.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

Component_Core::Component_Core()
    : CompoMe::Component() /* PROVIDE */, handle(this) /* DATA */,
      name(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      state(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  C_INFO_TAG("CONST: Component_Core", "Component,Component_Core");
  return;
}

//! Destructor
Component_Core::~Component_Core() noexcept {
  C_INFO_TAG("DEST: Component_Core", "Component,Component_Core");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Component_Core::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: Component_Core", "Component,Component_Core");
  this->set_state(this->get_state() | COMPONENT_STATE_CONFIGURED);

  // configuration: sub_componentreturn;
}

void Component_Core::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: Component_Core", "Component,Component_Core");
  this->set_state(this->get_state() | COMPONENT_STATE_CONNECTED);
  // connect: intern

  // connect: sub componentreturn;
}

void Component_Core::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: Component_Core", "Component,Component_Core");
  if (this->get_state() & COMPONENT_STATE_STARTED == COMPONENT_STATE_STARTED) {
    C_WARNING("This component is already started ... call stop before start or "
              "use restart ");
    return;
  }

  this->set_state(this->get_state() | COMPONENT_STATE_STARTED);

  // start: sub componentreturn;
}

void Component_Core::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: Component_Core", "Component,Component_Core");

  // step: receiver process// step: sub_componentreturn;
}

void Component_Core::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: Component_Core", "Component,Component_Core");
  if (this->get_state() & COMPONENT_STATE_STARTED != COMPONENT_STATE_STARTED) {
    C_WARNING("This component cannot be stop because they are not started");
    return;
  }

  this->set_state(this->get_state() - COMPONENT_STATE_STARTED);
  return;
}

void Component_Core::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: Component_Core", "Component,Component_Core");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

} // namespace CompoMe
