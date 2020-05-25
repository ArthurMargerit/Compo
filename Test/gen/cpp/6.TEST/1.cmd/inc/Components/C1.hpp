#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/exist.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/C1_Lapin_p1.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

class C1 : public Component {

public:
  // c++ 11 def
  //! construction
  C1();

  //! Destructor
  virtual ~C1() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////

  // PROVIDES

  C1_Lapin_p1 &get_p1();

  // FUNCTIONS

  // SUB COMPONENTS

  std::ostream &to_stream(std::ostream &os,
                          Serialization_context_export &p_ctx) const override;
  std::istream &from_stream(std::istream &is,
                            Serialization_context_import &p_ctx) override;

private:
  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  C1_Lapin_p1 p1;

public:
  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const C1 &c);
std::istream &operator>>(std::istream &is, C1 &c);
