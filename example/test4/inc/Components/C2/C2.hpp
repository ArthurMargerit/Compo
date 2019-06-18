#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Base.hpp"

// STRUCT

// INTERFACES

#include "Components/C2/C2_Ia_b.hpp"

#include "Interfaces/Ia/Ia.hpp"

namespace C2 {

class C2 : public Component {

public:
  // c++ 11 def
  //! construction
  C2();

  //! Copy constructor
  C2(const C2 &other) = delete;

  //! Move constructor
  C2(C2 &&other) = delete;

  //! Destructor
  virtual ~C2() noexcept;

  //! Copy assignment operator
  C2 &operator=(const C2 &other) = delete;

  //! Move assignment operator
  C2 &operator=(C2 &&other) noexcept = delete;

  // composant initialisation

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void stop();
  virtual void step();
  virtual void status();

  // DATA /////////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE

  Ia_b &get_b();

  // PROVIDE

  Ia *&get_a();

  // FUNCTIONS

private:
  // DATA /////////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE
  Ia_b b;

  // PROVIDE
  Ia *a;
};
} // namespace C2