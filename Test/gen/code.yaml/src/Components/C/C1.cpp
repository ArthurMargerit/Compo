
#include "Components/C/C1.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

namespace C {

C1::C1()
    : CompoMe::Component() /* PROVIDE */, p1(this) /* REQUIRE */, r1(NULL) {
  C_INFO_TAG("CONST: C1", "Component,C1");
  return;
}

//! Destructor
C1::~C1() noexcept {
  C_INFO_TAG("DEST: C1", "Component,C1");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C1::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: C1", "Component,C1");

  // configuration: sub_componentreturn;
}

void C1::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: C1", "Component,C1");

  // connect: intern

  // connect: sub componentreturn;
}

void C1::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: C1", "Component,C1");

  // start: sub componentreturn;
}

void C1::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: C1", "Component,C1");

  // step: receiver process// step: sub_componentreturn;
}

void C1::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: C1", "Component,C1");
  return;
}

void C1::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: C1", "Component,C1");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

} // namespace C