
#include "Components/Sensor.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

Sensor::Sensor()
    : /* PROVIDE */ information(this), capteur1(this),
      /* DATA */ name(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      type(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      location(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  C_INFO_TAG("CONST: Sensor", "Component,Sensor");
  return;
}

//! Destructor
Sensor::~Sensor() noexcept {
  C_INFO_TAG("DEST: Sensor", "Component,Sensor");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Sensor::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: Sensor", "Component,Sensor");

  // configuration: sub_componentreturn;
}

void Sensor::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: Sensor", "Component,Sensor");

  // connect: intern

  // connect: sub componentreturn;
}

void Sensor::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: Sensor", "Component,Sensor");

  // start: sub componentreturn;
}

void Sensor::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: Sensor", "Component,Sensor");

  // step: sub_componentreturn;
}

void Sensor::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: Sensor", "Component,Sensor");
  return;
}

void Sensor::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: Sensor", "Component,Sensor");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//
