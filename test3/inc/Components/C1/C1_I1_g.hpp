#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I1/I1.hpp"

namespace C1 {

class C1;

class I1_g : public ::I1 {
public:
  C1 *composant;

  //! Default constructor
  I1_g(C1 *comp);

  //! Destructor
  virtual ~I1_g() noexcept;

  I1_g() = delete;
  //! Copy constructor
  I1_g(const I1_g &other) = delete;
  //! Move constructor
  I1_g(I1_g &&other) = delete;
  // //! Copy assignment operator
  // I1& operator=(const I1 &other)=delete;
  // //! Move assignment operator
  // I1& operator=(I1 &&other) noexcept;
  virtual int add(int x, int y);

protected:
private:
};
};