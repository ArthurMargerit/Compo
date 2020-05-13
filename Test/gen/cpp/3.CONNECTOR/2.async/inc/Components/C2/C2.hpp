#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/b.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/C2/C2_Math_async_return_back_call.hpp"

// require

#include "Interfaces/Math_async_call/Math_async_call_fake.hpp"

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace C2 {

class C2 : public Component {

public:
  // c++ 11 def
  //! construction
  C2();

  // //! Copy constructor
  // C2(const C2 &other) = delete;

  // //! Move constructor
  // C2(C2 &&other) = delete;

  //! Destructor
  virtual ~C2() noexcept;

  // //! Copy assignment operator
  // C2& operator=(const C2::C2 &other) = delete;

  // //! Move assignment operator
  // C2& operator=(C2::C2 &&other) noexcept = delete;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // // REQUIRES
  //
  // void set_call(Math_async_call*);
  //

  // REQUIRES LISTS
  //

  // PROVIDES

  Math_async_return_back_call &get_back_call();

  // FUNCTIONS

  // SUB COMPONENTS

  std::ostream &to_stream(std::ostream &os,
                          Serialization_context_export &p_ctx) const override;
  std::istream &from_stream(std::istream &is,
                            Serialization_context_import &p_ctx) override;

private:
  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  Math_async_return_back_call back_call;

public:
  Require_helper_t<Math_async_call> call;

  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream &operator<<(std::ostream &os, const C2 &c);
std::istream &operator>>(std::istream &is, C2 &c);

// Pointer
std::istream &operator>>(std::istream &is, C2 *&c);
std::ostream &operator<<(std::ostream &os, const C2 *c);

// SmartPointer
std::istream &operator>>(std::istream &is, std::shared_ptr<C2> &c);
std::ostream &operator<<(std::ostream &os, const std::shared_ptr<C2> &c);
///////////////////////////////////////////////////////////////////////////////
} // namespace C2
