
#include "Components/Compute.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

Compute::Compute() : /* PROVIDE */ compute(this) {
  C_INFO_TAG("CONST: Compute", "Component,Compute");
  return;
}

//! Destructor
Compute::~Compute() noexcept {
  C_INFO_TAG("DEST: Compute", "Component,Compute");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Compute::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: Compute", "Component,Compute");

  // configuration: sub_componentreturn;
}

void Compute::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: Compute", "Component,Compute");

  // connect: intern

  // connect: sub componentreturn;
}

void Compute::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: Compute", "Component,Compute");

  // start: sub componentreturn;
}

void Compute::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: Compute", "Component,Compute");

  // step: sub_componentreturn;
}

void Compute::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: Compute", "Component,Compute");
  return;
}

void Compute::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: Compute", "Component,Compute");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//
