#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/code.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/C_p/C_p_I1_ii.hpp"

// require

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace C_p {

class C_p : public Component {

public:
  // c++ 11 def
  //! construction
  C_p();

  // //! Copy constructor
  // C_p(const C_p &other) = delete;

  // //! Move constructor
  // C_p(C_p &&other) = delete;

  //! Destructor
  virtual ~C_p() noexcept;

  // //! Copy assignment operator
  // C_p& operator=(const C_p::C_p &other) = delete;

  // //! Move assignment operator
  // C_p& operator=(C_p::C_p &&other) noexcept = delete;

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

  // REQUIRES LISTS

  // PROVIDES

  I1_ii &get_ii();

  // FUNCTIONS

  // SUB COMPONENTS

  // PACK/UNPACK
  void save(std::ostream &os) const;
  void load(std::istream &is);

private:
  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  I1_ii ii;

public:
private:
  // REQUIRE_LIST

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////

  // EXTRA ////////////////////////////////////////////////////////////////////
};
} // namespace C_p
