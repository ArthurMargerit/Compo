#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/test2.hpp"

// STRUCT

#include "Data/Struct_A.hpp"

// INTERFACES

#include "Components/C_t1p/C_t1p_I_t2_i_p.hpp"

#include "Components/C_t1p/C_t1p_I_t1_i_p2.hpp"

namespace C_t1p {

class C_t1p : public Component {

public:
  // c++ 11 def
  //! construction
  C_t1p();

  //! Copy constructor
  C_t1p(const C_t1p &other) = delete;

  //! Move constructor
  C_t1p(C_t1p &&other) = delete;

  //! Destructor
  virtual ~C_t1p() noexcept;

  //! Copy assignment operator
  C_t1p &operator=(const C_t1p &other) = delete;

  //! Move assignment operator
  C_t1p &operator=(C_t1p &&other) noexcept = delete;

  // composant initialisation

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void stop();
  virtual void step();
  virtual void status();

  // DATA /////////////////////////////////////////////////////////////////////
  // a
  A get_a() const;
  void set_a(const A a);

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE

  I_t2_i_p &get_i_p();

  I_t1_i_p2 &get_i_p2();

  // PROVIDE

  // FUNCTIONS

private:
  // DATA /////////////////////////////////////////////////////////////////////
  A a;

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE
  I_t2_i_p i_p;
  I_t1_i_p2 i_p2;

  // PROVIDE
};
}