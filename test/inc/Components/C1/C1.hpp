#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

#include "Components/C1/C1_I1_a.hpp"

#include "Components/C1/C1_I1_b.hpp"

#include "Components/C1/C1_I1_g.hpp"

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/I1/I1.hpp"

namespace C1 {

class C1 : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  I1_a a;

  I1_b b;

  I1_g g;

  // Facette

  I1 *c;

  I1 *d;

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

  // GET SET

  // function

private:
protected:
};
}