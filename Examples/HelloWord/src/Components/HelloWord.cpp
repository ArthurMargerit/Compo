
#include "Components/HelloWord.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

HelloWord::HelloWord() : /* PROVIDE */ inter(this) {
  C_INFO_TAG("CONST: HelloWord", "Component,HelloWord");
  return;
}

//! Destructor
HelloWord::~HelloWord() noexcept {
  C_INFO_TAG("DEST: HelloWord", "Component,HelloWord");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void HelloWord::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: HelloWord", "Component,HelloWord");

  // configuration: sub_componentreturn;
}

void HelloWord::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: HelloWord", "Component,HelloWord");

  // connect: intern

  // connect: sub componentreturn;
}

void HelloWord::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: HelloWord", "Component,HelloWord");

  // start: sub componentreturn;
}

void HelloWord::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: HelloWord", "Component,HelloWord");

  // step: sub_componentreturn;
}

void HelloWord::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: HelloWord", "Component,HelloWord");
  return;
}

void HelloWord::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: HelloWord", "Component,HelloWord");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//
