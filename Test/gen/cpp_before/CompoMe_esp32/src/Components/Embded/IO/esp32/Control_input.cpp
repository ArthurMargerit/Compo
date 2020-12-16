
#include "Components/Embded/IO/esp32/Control_input.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

namespace Embded {

namespace IO {

namespace esp32 {

Control_input::Control_input()
    : CompoMe::Component() /* PROVIDE */, control(this) /* DATA */,
      pool_down(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      pool_up(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      pin_id(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  C_INFO_TAG("CONST: Control_input", "Component,Control_input");
  return;
}

//! Destructor
Control_input::~Control_input() noexcept {
  C_INFO_TAG("DEST: Control_input", "Component,Control_input");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Control_input::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: Control_input", "Component,Control_input");

  // configuration: sub_componentreturn;
}

void Control_input::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: Control_input", "Component,Control_input");

  // connect: intern

  // connect: sub componentreturn;
}

void Control_input::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: Control_input", "Component,Control_input");

  // start: sub componentreturn;
}

void Control_input::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: Control_input", "Component,Control_input");

  // step: receiver process// step: sub_componentreturn;
}

void Control_input::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: Control_input", "Component,Control_input");
  return;
}

void Control_input::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: Control_input", "Component,Control_input");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

} // namespace esp32

} // namespace IO

} // namespace Embded
