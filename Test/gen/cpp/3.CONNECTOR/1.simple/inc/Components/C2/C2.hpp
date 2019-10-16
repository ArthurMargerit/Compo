#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/code.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/C2/C2_Math_async_return_back_call.hpp"

// require

#include "Interfaces/Math_async_call/Math_async_call.hpp"

// SUB COMPONENT

namespace C2 {

class C2 : public Component {

public:
  // c++ 11 def
  //! construction
  C2();

  //! Copy constructor
  C2(const C2 &other) = delete;

  //! Move constructor
  C2(C2 &&other) = delete;

  //! Destructor
  virtual ~C2() noexcept;

  //! Copy assignment operator
  C2 &operator=(const C2 &other) = delete;

  //! Move assignment operator
  C2 &operator=(C2 &&other) noexcept = delete;

  // composant initialisation

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void stop();
  virtual void step();
  virtual void status();

  // DATA /////////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRES

  Math_async_return_back_call &get_back_call();

  // PROVIDES

  void set_call(Math_async_call *);

  // FUNCTIONS

  // SUB COMPONENTS

  //private:
  // DATA /////////////////////////////////////////////////////////////////////

  // INTERFACE ////////////////////////////////////////////////////////////////
  // REQUIRE
  Math_async_return_back_call back_call;

  // PROVIDE
  Math_async_call *call;

  // SUB COMPONENT ////////////////////////////////////////////////////////////
};
}
