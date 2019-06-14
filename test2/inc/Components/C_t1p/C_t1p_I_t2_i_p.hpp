#pragma once

#include "Data/test2.hpp"

#include "Interfaces/I_t2/I_t2.hpp"

namespace C_t1p {

class C_t1p;

class I_t2_i_p : public ::I_t2 {
public:
  C_t1p *composant;

  //! Default constructor
  I_t2_i_p(C_t1p *comp);

  //! Destructor
  virtual ~I_t2_i_p() noexcept;

  I_t2_i_p() = delete;
  //! Copy constructor
  I_t2_i_p(const I_t2_i_p &other) = delete;
  //! Move constructor
  I_t2_i_p(I_t2_i_p &&other) = delete;
  // //! Copy assignment operator
  // I_t2& operator=(const I_t2 &other)=delete;
  // //! Move assignment operator
  // I_t2& operator=(I_t2 &&other) noexcept;

protected:
private:
};
};