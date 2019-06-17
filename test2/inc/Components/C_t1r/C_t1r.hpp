#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/test2.hpp"

// STRUCT

#include "Data/Struct_A.hpp"

// INTERFACES

#include "Interfaces/I_t1/I_t1.hpp"

namespace C_t1r {

class C_t1r : public Component {

public:
  // c++ 11 def
  //! construction
  C_t1r();

  //! Copy constructor
  C_t1r(const C_t1r &other) = delete;

  //! Move constructor
  C_t1r(C_t1r &&other) = delete;

  //! Destructor
  virtual ~C_t1r() noexcept;

  //! Copy assignment operator
  C_t1r &operator=(const C_t1r &other) = delete;

  //! Move assignment operator
  C_t1r &operator=(C_t1r &&other) noexcept = delete;

  // composant initialisation

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void stop();
  virtual void step();
  virtual void status();

  // DATA /////////////////////////////////////////////////////////////////////
  // b
  A get_b() const;
  void set_b(const A b);

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE

  // PROVIDE

  I_t1 *&get_i_r();

  // FUNCTIONS

private:
  // DATA /////////////////////////////////////////////////////////////////////
  A b;

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE

  // PROVIDE
  I_t1 *i_r;
};
}