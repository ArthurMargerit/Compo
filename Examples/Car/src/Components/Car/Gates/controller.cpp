
#include "Components/Car/Gates/controller.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

namespace Car {

namespace Gates {

controller::controller()
    : /* PROVIDE */ win(this), locker(this),
      /* REQUIRE */ reporting_station(NULL) {
  C_INFO_TAG("CONST: controller", "Component,controller");
  return;
}

//! Destructor
controller::~controller() noexcept {
  C_INFO_TAG("DEST: controller", "Component,controller");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void controller::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: controller", "Component,controller");

  // configuration: sub_componentreturn;
}

void controller::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: controller", "Component,controller");

  // connect: intern

  // connect: sub componentreturn;
}

void controller::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: controller", "Component,controller");

  // start: sub componentreturn;
}

void controller::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: controller", "Component,controller");

  // step: sub_componentreturn;
}

void controller::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: controller", "Component,controller");
  return;
}

void controller::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: controller", "Component,controller");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

} // namespace Gates

} // namespace Car
