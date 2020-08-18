
#include <algorithm>
#include <iostream>

#include "Components/C2.hpp"

C2::C2() : /* PROVIDE */ back_call(this), /* REQUIRE */ call(NULL) {
  std::cout << "--CONST : C2" << std::endl;
  return;
}

//! Destructor
C2::~C2() noexcept {
  std::cout << "--DEST  : C2" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C2::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C2" << std::endl;

  // configuration: sub_componentreturn;
}

void C2::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: C2" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void C2::start() {
  // start: parent
  Component::start();
  std::cout << "--START : C2" << std::endl;

  // start: sub componentreturn;
}

void C2::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : C2" << std::endl;

  // step: sub_componentreturn;
}

void C2::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : C2" << std::endl;
  return;
}

void C2::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: C2" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

C2_Math_async_return_back_call &C2::get_back_call() { return this->back_call; }

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////
