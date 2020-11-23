
#include "Components/C2.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

C2::C2() : /* PROVIDE */ back_call(this), /* REQUIRE */ call(NULL) {
  C_INFO_TAG("CONST: C2", "Component,C2");
  return;
}

//! Destructor
C2::~C2() noexcept {
  C_INFO_TAG("DEST: C2", "Component,C2");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C2::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: C2", "Component,C2");

  // configuration: sub_componentreturn;
}

void C2::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: C2", "Component,C2");

  // connect: intern

  // connect: sub componentreturn;
}

void C2::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: C2", "Component,C2");

  // start: sub componentreturn;
}

void C2::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: C2", "Component,C2");

  // step: sub_componentreturn;
}

void C2::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: C2", "Component,C2");
  return;
}

void C2::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: C2", "Component,C2");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//
