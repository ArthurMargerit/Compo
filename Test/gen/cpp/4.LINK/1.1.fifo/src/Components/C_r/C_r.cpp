
#include <algorithm>
#include <iostream>

#include "Components/C_r/C_r.hpp"

#include "Interfaces/I1/I1_fake.hpp"

namespace C_r {

C_r::C_r() : /* REQUIRE */ io(NULL) {
  std::cout << "--CONST : C_r" << std::endl;
  return;
}

//! Destructor
C_r::~C_r() noexcept {
  std::cout << "--DEST  : C_r" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C_r::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C_r" << std::endl;

  // configuration: sub_componentreturn;
}

void C_r::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: C_r" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void C_r::start() {
  // start: parent
  Component::start();
  std::cout << "--START : C_r" << std::endl;

  // start: sub componentreturn;
}

void C_r::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : C_r" << std::endl;

  // step: sub_componentreturn;
}

void C_r::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : C_r" << std::endl;
  return;
}

void C_r::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: C_r" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

// REQUIRE //////////////////////////////////////////////////////////////////

void C_r::set_io(I1 *p_r) { this->io = p_r; }

Fake *C_r::fake_io() {
  I1_fake *f = new I1_fake();
  this->set_io(f);
  return f;
}

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
void C_r::save(std::ostream &os) const {
  os << "{";
  os << "type:"
     << "C_r";

  os << ",require:{";

  os << "io:" << this->io;

  os << "}";
  os << "}";
}

void C_r::load(std::istream &is) {
  // TODO
}

} // namespace C_r