#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

#include "Interfaces/I1/I1.hpp"

namespace C4 {

class C4 : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  // Facette

  I1 *a;

  // c++ 11 def
  //! construction
  C4();

  //! Copy constructor
  C4(const C4 &other) = delete;

  //! Move constructor
  C4(C4 &&other) = delete;

  //! Destructor
  virtual ~C4() noexcept;

  //! Copy assignment operator
  C4 &operator=(const C4 &other) = delete;

  //! Move assignment operator
  C4 &operator=(C4 &&other) noexcept = delete;

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