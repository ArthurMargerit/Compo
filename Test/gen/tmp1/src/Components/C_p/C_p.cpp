
#include <algorithm>
#include <iostream>

#include "Components/C_p/C_p.hpp"

namespace C_p {

C_p::C_p() : /* PROVIDE */ ii(this) {
  std::cout << "--CONST : C_p" << std::endl;
  return;
}

//! Destructor
C_p::~C_p() noexcept {
  std::cout << "--DEST  : C_p" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C_p::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C_p" << std::endl;

  // configuration: sub_componentreturn;
}

void C_p::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: C_p" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void C_p::start() {
  // start: parent
  Component::start();
  std::cout << "--START : C_p" << std::endl;

  // start: sub componentreturn;
}

void C_p::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : C_p" << std::endl;

  // step: sub_componentreturn;
}

void C_p::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : C_p" << std::endl;
  return;
}

void C_p::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: C_p" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

I1_ii &C_p::get_ii() { return this->ii; }

// REQUIRE_LIST /////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
void C_p::save(std::ostream &os) const {
  os << "{";
  os << "type:"
     << "C_p";

  os << ",provide:{";

  os << "ii:";
  this->ii.save(os);

  os << "}"; // os << "}";
}

void C_p::load(std::istream &is) {
  // TODO
}

} // namespace C_p
