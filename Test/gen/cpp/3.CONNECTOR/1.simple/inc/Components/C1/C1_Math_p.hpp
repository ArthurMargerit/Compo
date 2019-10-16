#pragma once

#include "Data/code.hpp"

#include "Interfaces/Math/Math.hpp"

namespace C1 {

class C1;

class Math_p : public ::Math {
public:
  C1 *composant;

  //! Default constructor
  Math_p(C1 *comp);

  //! Destructor
  virtual ~Math_p() noexcept;

  Math_p() = delete;
  //! Copy constructor
  Math_p(const Math_p &other) = delete;
  //! Move constructor
  Math_p(Math_p &&other) = delete;
  // //! Copy assignment operator
  // Math& operator=(const Math &other)=delete;
  // //! Move assignment operator
  // Math& operator=(Math &&other) noexcept;

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Math /////////////////////////////////////////////////////////
  virtual int ping(int a, int b);
  virtual int f1(int a);
  virtual int f2();
  virtual void f3();

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Math ///////////////////////////////////////////////////////////////////
  // get/set a
  virtual int get_a() const;
  virtual void set_a(const int a);
  // get/set b
  virtual int get_b() const;
  virtual void set_b(const int b);

private:
  C1 &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Math
  int a;
  int b;
};
};