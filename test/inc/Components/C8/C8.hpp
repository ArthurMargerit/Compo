#pragma once

#include "Components/C6/C6.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

namespace C8 {

class C8 : public C6::C6 {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  // Facette

  // c++ 11 def
  //! construction
  C8();

  //! Copy constructor
  C8(const C8 &other) = delete;

  //! Move constructor
  C8(C8 &&other) = delete;

  //! Destructor
  virtual ~C8() noexcept;

  //! Copy assignment operator
  C8 &operator=(const C8 &other) = delete;

  //! Move assignment operator
  C8 &operator=(C8 &&other) noexcept = delete;

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