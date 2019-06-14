#pragma once

#include "Components/C_t1r/C_t1r.hpp"

// TYPE
#include "Data/test2.hpp"

// STRUCT

#include "Data/Struct_A.hpp"

// INTERFACES

namespace C_t2r {

class C_t2r : public C_t1r::C_t1r {

public:
  // c++ 11 def
  //! construction
  C_t2r();

  //! Copy constructor
  C_t2r(const C_t2r &other) = delete;

  //! Move constructor
  C_t2r(C_t2r &&other) = delete;

  //! Destructor
  virtual ~C_t2r() noexcept;

  //! Copy assignment operator
  C_t2r &operator=(const C_t2r &other) = delete;

  //! Move assignment operator
  C_t2r &operator=(C_t2r &&other) noexcept = delete;

  // composant initialisation

  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // DATA /////////////////////////////////////////////////////////////////////
  // c
  A get_c() const;
  void set_c(const A c);

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE

  // PROVIDE

  // FUNCTIONS

private:
  // DATA /////////////////////////////////////////////////////////////////////
  A c;

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE

  // PROVIDE
};
}