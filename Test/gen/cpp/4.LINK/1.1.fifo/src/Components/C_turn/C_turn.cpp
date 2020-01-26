
#include <algorithm>
#include <iostream>

#include "Components/C_turn/C_turn.hpp"

#include "Interfaces/I1/I1_fake.hpp"

namespace C_turn {

C_turn::C_turn()
    : /* PROVIDE */ ii(this), /* REQUIRE */ io(NULL),
      /* COMPONENT_INSTANCE */ cp(), cr() {
  std::cout << "--CONST : C_turn" << std::endl;
  return;
}

//! Destructor
C_turn::~C_turn() noexcept {
  std::cout << "--DEST  : C_turn" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C_turn::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C_turn" << std::endl;

  // configuration: sub_component
  cp.configuration();
  cr.configuration();
  return;
}

void C_turn::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: C_turn" << std::endl;

  // connect: intern

  // connect: sub component
  cp.connection();
  cr.connection();
  return;
}

void C_turn::start() {
  // start: parent
  Component::start();
  std::cout << "--START : C_turn" << std::endl;

  // start: sub component
  cp.start();
  cr.start();
  return;
}

void C_turn::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : C_turn" << std::endl;

  // step: sub_component
  cp.step();
  cr.step();
  return;
}

void C_turn::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : C_turn" << std::endl;
  cp.stop();
  cr.stop();
  return;
}

void C_turn::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: C_turn" << std::endl;
  cp.status();
  cr.status();
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

I1_ii &C_turn::get_ii() { return this->ii; }

// REQUIRE //////////////////////////////////////////////////////////////////

void C_turn::set_io(I1 *p_r) {

  // cr.io >-| io
  this->get_sc_cr().set_io(p_r);

  this->io = p_r;
}

Fake *C_turn::fake_io() {
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

C_p::C_p &C_turn::get_sc_cp() { return this->cp; }

C_r::C_r &C_turn::get_sc_cr() { return this->cr; }

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
void C_turn::save(std::ostream &os) const {
  os << "{";
  os << "type:"
     << "C_turn";

  os << ",provide:{";

  os << "ii:";
  this->ii.save(os);

  os << "}";
  os << ",require:{";

  os << "io:" << this->io;

  os << "}";
  os << ",components:{";

  os << "cp:";
  this->cp.save(os);
  os << ",";
  os << "cr:";
  this->cr.save(os);

  os << "}";
  os << "}";
}

void C_turn::load(std::istream &is) {
  // TODO
}

} // namespace C_turn