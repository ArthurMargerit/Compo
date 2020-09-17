
#include "Components/CompoMe/Log/To_Stream.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

namespace CompoMe {

namespace Log {

To_Stream::To_Stream() : /* PROVIDE */ log(this) {
  C_INFO_TAG("CONST: To_Stream", "Component,To_Stream");
  return;
}

//! Destructor
To_Stream::~To_Stream() noexcept {
  C_INFO_TAG("DEST: To_Stream", "Component,To_Stream");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void To_Stream::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: To_Stream", "Component,To_Stream");

  // configuration: sub_componentreturn;
}

void To_Stream::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: To_Stream", "Component,To_Stream");

  // connect: intern

  // connect: sub componentreturn;
}

void To_Stream::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: To_Stream", "Component,To_Stream");

  // start: sub componentreturn;
}

void To_Stream::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: To_Stream", "Component,To_Stream");

  // step: sub_componentreturn;
}

void To_Stream::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: To_Stream", "Component,To_Stream");
  return;
}

void To_Stream::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: To_Stream", "Component,To_Stream");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

To_Stream_Log_I_log &To_Stream::get_log() { return this->log; }

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace Log

} // namespace CompoMe
