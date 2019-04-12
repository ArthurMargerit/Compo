#pragma once

#include "Components/C6/C6.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

namespace C7 {

class C7 : public C6::C6 {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  // Facette

  // c++ 11 def
  //! construction
  C7();

  //! Copy constructor
  C7(const C7 &other) = delete;

  //! Move constructor
  C7(C7 &&other) = delete;

  //! Destructor
  virtual ~C7() noexcept;

  //! Copy assignment operator
  C7 &operator=(const C7 &other) = delete;

  //! Move assignment operator
  C7 &operator=(C7 &&other) noexcept = delete;

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