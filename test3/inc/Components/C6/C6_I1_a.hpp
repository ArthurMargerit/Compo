#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I1/I1.hpp"

namespace C6 {

class C6;

class I1_a : public ::I1 {
public:
  C6 *composant;

  //! Default constructor
  I1_a(C6 *comp);

  //! Destructor
  virtual ~I1_a() noexcept;

  I1_a() = delete;
  //! Copy constructor
  I1_a(const I1_a &other) = delete;
  //! Move constructor
  I1_a(I1_a &&other) = delete;
  // //! Copy assignment operator
  // I1& operator=(const I1 &other)=delete;
  // //! Move assignment operator
  // I1& operator=(I1 &&other) noexcept;
  virtual int add(int x, int y);

protected:
private:
};
};