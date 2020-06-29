#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/b.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/C2_Math_async_return_back_call.hpp"

// require

#include "Interfaces/Math_async_call/Math_async_call.hpp"

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

class C2 : public Component {

public:
  // c++ 11 def
  //! construction
  C2();

  //! Destructor
  virtual ~C2() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////

  // PROVIDES

  C2_Math_async_return_back_call &get_back_call();

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
  C2_Math_async_return_back_call back_call;

public:
  Require_helper_t<Math_async_call> call;

  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const C2 &c);
std::istream &operator>>(std::istream &is, C2 &c);
