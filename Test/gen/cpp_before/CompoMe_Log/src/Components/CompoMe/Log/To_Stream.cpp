
#include <algorithm>
#include <iostream>

#include "Components/CompoMe/Log/To_Stream.hpp"

namespace CompoMe {

namespace Log {

To_Stream::To_Stream() : /* PROVIDE */ log(this) {
  std::cout << "--CONST : To_Stream" << std::endl;
  return;
}

//! Destructor
To_Stream::~To_Stream() noexcept {
  std::cout << "--DEST  : To_Stream" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void To_Stream::configuration() {
  Component::configuration();
  std::cout << "--CONF  : To_Stream" << std::endl;

  // configuration: sub_componentreturn;
}

void To_Stream::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: To_Stream" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void To_Stream::start() {
  // start: parent
  Component::start();
  std::cout << "--START : To_Stream" << std::endl;

  // start: sub componentreturn;
}

void To_Stream::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : To_Stream" << std::endl;

  // step: sub_componentreturn;
}

void To_Stream::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : To_Stream" << std::endl;
  return;
}

void To_Stream::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: To_Stream" << std::endl;
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
