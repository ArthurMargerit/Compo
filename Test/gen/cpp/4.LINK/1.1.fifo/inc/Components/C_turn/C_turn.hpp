#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/base.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/C_turn/C_turn_I1_ii.hpp"

// require

#include "Interfaces/I1/I1.hpp"

// SUB COMPONENT  ////////////////////////////////////////////////////////////

#include "Components/C_p/C_p.hpp"

#include "Components/C_r/C_r.hpp"

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace C_turn {

class C_turn : public Component {

public:
  // c++ 11 def
  //! construction
  C_turn();

  //! Copy constructor
  C_turn(const C_turn &other) = delete;

  //! Move constructor
  C_turn(C_turn &&other) = delete;

  //! Destructor
  virtual ~C_turn() noexcept;

  //! Copy assignment operator
  C_turn &operator=(const C_turn &other) = delete;

  //! Move assignment operator
  C_turn &operator=(C_turn &&other) noexcept = delete;

  // composant initialisation

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void stop();
  virtual void step();
  virtual void status();

  // GET/SET //////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRES

  void set_io(I1 *);

  Fake *fake_io();

  // REQUIRES LISTS

  // PROVIDES

  I1_ii &get_ii();

  // FUNCTIONS

  // SUB COMPONENTS

  C_p::C_p &get_sc_cp();

  C_r::C_r &get_sc_cr();

  // PACK/UNPACK
  void save(std::ostream &os) const;
  void load(std::istream &is);

private:
  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  I1_ii ii;

  // REQUIRE
  I1 *io;

  // REQUIRE_LIST

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////
  C_p::C_p cp;
  C_r::C_r cr;

  // SUB CONNECTOR ////////////////////////////////////////////////////////////

  // EXTRA ////////////////////////////////////////////////////////////////////
};
} // namespace C_turn