#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/code.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/C_p_I1_ii.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

class C_p : public Component {

public:
  // c++ 11 def
  //! construction
  C_p();

  //! Destructor
  virtual ~C_p() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////

  // PROVIDES

  C_p_I1_ii &get_ii();

  // FUNCTIONS

  // SUB COMPONENTS

private:
  std::ostream &to_stream_data(std::ostream &,
                               Serialization_context_export &) const;
  std::ostream &to_stream_sc(std::ostream &,
                             Serialization_context_export &) const;
  std::ostream &to_stream_provide(std::ostream &,
                                  Serialization_context_export &) const;

  std::istream &from_stream_data(std::istream &,
                                 Serialization_context_import &);
  std::istream &from_stream_sc(std::istream &, Serialization_context_import &);
  std::istream &from_stream_provide(std::istream &,
                                    Serialization_context_import &);

public:
  std::ostream &to_stream(std::ostream &os,
                          Serialization_context_export &p_ctx) const override;
  std::istream &from_stream(std::istream &is,
                            Serialization_context_import &p_ctx) override;

  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  C_p_I1_ii ii;

public:
  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const C_p &c);
std::istream &operator>>(std::istream &is, C_p &c);
