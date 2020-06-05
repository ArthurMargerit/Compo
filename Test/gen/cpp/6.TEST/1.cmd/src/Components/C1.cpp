
#include <algorithm>
#include <iostream>

#include "Components/C1.hpp"

C1::C1() : /* PROVIDE */ p1(this) {
  std::cout << "--CONST : C1" << std::endl;
  return;
}

//! Destructor
C1::~C1() noexcept {
  std::cout << "--DEST  : C1" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C1::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C1" << std::endl;

  // configuration: sub_componentreturn;
}

void C1::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: C1" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void C1::start() {
  // start: parent
  Component::start();
  std::cout << "--START : C1" << std::endl;

  // start: sub componentreturn;
}

void C1::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : C1" << std::endl;

  // step: sub_componentreturn;
}

void C1::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : C1" << std::endl;
  return;
}

void C1::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: C1" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

C1_Lapin_p1 &C1::get_p1() { return this->p1; }

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////
