#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/I1/I1.hpp"

namespace C3 {

class C3 : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  // Facette

  I1 *c;

  I1 *d;

  // c++ 11 def
  //! construction
  C3();

  //! Copy constructor
  C3(const C3 &other) = delete;

  //! Move constructor
  C3(C3 &&other) = delete;

  //! Destructor
  virtual ~C3() noexcept;

  //! Copy assignment operator
  C3 &operator=(const C3 &other) = delete;

  //! Move assignment operator
  C3 &operator=(C3 &&other) noexcept = delete;

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