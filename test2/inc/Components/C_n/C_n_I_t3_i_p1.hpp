#pragma once

#include "Data/test2.hpp"

#include "Interfaces/I_t3/I_t3.hpp"

namespace C_n {

class C_n;

class I_t3_i_p1 : public ::I_t3 {
public:
  C_n *composant;

  //! Default constructor
  I_t3_i_p1(C_n *comp);

  //! Destructor
  virtual ~I_t3_i_p1() noexcept;

  I_t3_i_p1() = delete;
  //! Copy constructor
  I_t3_i_p1(const I_t3_i_p1 &other) = delete;
  //! Move constructor
  I_t3_i_p1(I_t3_i_p1 &&other) = delete;
  // //! Copy assignment operator
  // I_t3& operator=(const I_t3 &other)=delete;
  // //! Move assignment operator
  // I_t3& operator=(I_t3 &&other) noexcept;

protected:
private:
};
};