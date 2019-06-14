#pragma once

#include "Components/C_t1p/C_t1p.hpp"

// TYPE
#include "Data/test2.hpp"

// STRUCT

#include "Data/Struct_A.hpp"

// INTERFACES

namespace C_t2p {

class C_t2p : public C_t1p::C_t1p {

public:
  // c++ 11 def
  //! construction
  C_t2p();

  //! Copy constructor
  C_t2p(const C_t2p &other) = delete;

  //! Move constructor
  C_t2p(C_t2p &&other) = delete;

  //! Destructor
  virtual ~C_t2p() noexcept;

  //! Copy assignment operator
  C_t2p &operator=(const C_t2p &other) = delete;

  //! Move assignment operator
  C_t2p &operator=(C_t2p &&other) noexcept = delete;

  // composant initialisation

  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // DATA /////////////////////////////////////////////////////////////////////
  // d
  A get_d() const;
  void set_d(const A d);

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE

  // PROVIDE

  // FUNCTIONS

private:
  // DATA /////////////////////////////////////////////////////////////////////
  A d;

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE

  // PROVIDE
};
}