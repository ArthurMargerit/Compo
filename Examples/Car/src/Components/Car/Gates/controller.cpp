
#include <algorithm>
#include <iostream>

#include "Components/Car/Gates/controller.hpp"

#include "Interfaces/Car/Reporter/Reporter_fake.hpp"

namespace Car {

namespace Gates {

controller::controller()
    : /* PROVIDE */ win(this), locker(this),
      /* REQUIRE */ reporting_station(NULL) {
  std::cout << "--CONST : controller" << std::endl;
  return;
}

//! Destructor
controller::~controller() noexcept {
  std::cout << "--DEST  : controller" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void controller::configuration() {
  Component::configuration();
  std::cout << "--CONF  : controller" << std::endl;

  // configuration: sub_componentreturn;
}

void controller::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: controller" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void controller::start() {
  // start: parent
  Component::start();
  std::cout << "--START : controller" << std::endl;

  // start: sub componentreturn;
}

void controller::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : controller" << std::endl;

  // step: sub_componentreturn;
}

void controller::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : controller" << std::endl;
  return;
}

void controller::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: controller" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

controller_Window_win &controller::get_win() { return this->win; }

controller_Locker_locker &controller::get_locker() { return this->locker; }

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace Gates

} // namespace Car
