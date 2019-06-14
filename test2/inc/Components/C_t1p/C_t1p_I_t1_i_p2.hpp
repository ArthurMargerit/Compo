#pragma once

#include "Data/test2.hpp"

#include "Interfaces/I_t1/I_t1.hpp"

namespace C_t1p {

class C_t1p;

class I_t1_i_p2 : public ::I_t1 {
public:
  C_t1p *composant;

  //! Default constructor
  I_t1_i_p2(C_t1p *comp);

  //! Destructor
  virtual ~I_t1_i_p2() noexcept;

  I_t1_i_p2() = delete;
  //! Copy constructor
  I_t1_i_p2(const I_t1_i_p2 &other) = delete;
  //! Move constructor
  I_t1_i_p2(I_t1_i_p2 &&other) = delete;
  // //! Copy assignment operator
  // I_t1& operator=(const I_t1 &other)=delete;
  // //! Move assignment operator
  // I_t1& operator=(I_t1 &&other) noexcept;

protected:
private:
};
};