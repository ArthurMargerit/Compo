#pragma once

#include "Components/Component.hpp"
#include "Components/Require_helper_t.hpp"

// TYPE
#include "Data/code.hpp"

// STRUCT

// INTERFACES
// provide

// require

#include "Interfaces/I1/I1.hpp"

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace C_r {

class C_r : public Component {

public:
  // c++ 11 def
  //! construction
  C_r();

  // //! Copy constructor
  // C_r(const C_r &other) = delete;

  // //! Move constructor
  // C_r(C_r &&other) = delete;

  //! Destructor
  virtual ~C_r() noexcept;

  // //! Copy assignment operator
  // C_r& operator=(const C_r::C_r &other) = delete;

  // //! Move assignment operator
  // C_r& operator=(C_r::C_r &&other) noexcept = delete;

  // composant initialisation

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void stop();
  virtual void step();
  virtual void status();

  // GET/SET //////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // // REQUIRES
  //
  // void set_io(I1*);
  //

  // REQUIRES LISTS

  // PROVIDES

  // FUNCTIONS

  // SUB COMPONENTS

  // PACK/UNPACK
  void save(std::ostream &os) const;
  void load(std::istream &is);

private:
  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE

public:
  Require_helper_t<I1> io;

private:
  // REQUIRE_LIST

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////

  // EXTRA ////////////////////////////////////////////////////////////////////
};
} // namespace C_r
