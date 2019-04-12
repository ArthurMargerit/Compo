#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

#include "Components/C6/C6_I1_a.hpp"

#include "Interfaces/I1/I1.hpp"

namespace C6 {

class C6 : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  I1_a a;

  // Facette

  I1 *b;

  // c++ 11 def
  //! construction
  C6();

  //! Copy constructor
  C6(const C6 &other) = delete;

  //! Move constructor
  C6(C6 &&other) = delete;

  //! Destructor
  virtual ~C6() noexcept;

  //! Copy assignment operator
  C6 &operator=(const C6 &other) = delete;

  //! Move assignment operator
  C6 &operator=(C6 &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  int get_v1() const { return v1; }

  void set_v1(const int v1) { this->v1 = v1; }

  int get_v2() const { return v2; }

  void set_v2(const int v2) { this->v2 = v2; }

  int get_v3() const { return v3; }

  void set_v3(const int v3) { this->v3 = v3; }

  // function

private:
  int v1;

  int v2;

  int v3;

protected:
};
}