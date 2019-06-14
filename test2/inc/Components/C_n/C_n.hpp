#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/test2.hpp"

// STRUCT

// INTERFACES

#include "Components/C_n/C_n_I_t3_i_p1.hpp"

#include "Components/C_n/C_n_I_t4_i_p2.hpp"

#include "Interfaces/I_t2/I_t2.hpp"

#include "Interfaces/I_t3/I_t3.hpp"

#include "Interfaces/I_t4/I_t4.hpp"

namespace C_n {

class C_n : public Component {

public:
  // c++ 11 def
  //! construction
  C_n();

  //! Copy constructor
  C_n(const C_n &other) = delete;

  //! Move constructor
  C_n(C_n &&other) = delete;

  //! Destructor
  virtual ~C_n() noexcept;

  //! Copy assignment operator
  C_n &operator=(const C_n &other) = delete;

  //! Move assignment operator
  C_n &operator=(C_n &&other) noexcept = delete;

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

  I_t3_i_p1 &get_i_p1();

  I_t4_i_p2 &get_i_p2();

  // PROVIDE

  I_t2 *&get_i_r();

  I_t3 *&get_i_r1();

  I_t4 *&get_i_r2();

  // FUNCTIONS

private:
  // DATA /////////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE
  I_t3_i_p1 i_p1;
  I_t4_i_p2 i_p2;

  // PROVIDE
  I_t2 *i_r;
  I_t3 *i_r1;
  I_t4 *i_r2;
};
}