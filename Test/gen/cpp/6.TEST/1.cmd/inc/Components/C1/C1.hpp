#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/exist.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/C1/C1_Lapin_p1.hpp"

// require

// SUB COMPONENT

namespace C1 {

class C1 : public Component {

public:
  // c++ 11 def
  //! construction
  C1();

  //! Copy constructor
  C1(const C1 &other) = delete;

  //! Move constructor
  C1(C1 &&other) = delete;

  //! Destructor
  virtual ~C1() noexcept;

  //! Copy assignment operator
  C1 &operator=(const C1 &other) = delete;

  //! Move assignment operator
  C1 &operator=(C1 &&other) noexcept = delete;

  // composant initialisation

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void stop();
  virtual void step();
  virtual void status();

  // DATA /////////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRES

  Lapin_p1 &get_p1();

  // PROVIDES

  // FUNCTIONS

  // SUB COMPONENTS

private:
  // DATA /////////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE
  Lapin_p1 p1;

  // PROVIDE

  // SUB COMPONENT ////////////////////////////////////////////////////////////
};
}