#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

#include "Data/Struct_Pair.hpp"

// INTERFACES

#include "Components/C5/C5_I1_a.hpp"

namespace C5 {

class C5 : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  I1_a a;

  // Facette

  // c++ 11 def
  //! construction
  C5();

  //! Copy constructor
  C5(const C5 &other) = delete;

  //! Move constructor
  C5(C5 &&other) = delete;

  //! Destructor
  virtual ~C5() noexcept;

  //! Copy assignment operator
  C5 &operator=(const C5 &other) = delete;

  //! Move assignment operator
  C5 &operator=(C5 &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  Pair get_p() const { return p; }

  void set_p(const Pair p) { this->p = p; }

  // function

  virtual int f1();

  virtual int f2(int a);

  virtual int f3(int a, int b);

private:
  Pair p;

protected:
};
}