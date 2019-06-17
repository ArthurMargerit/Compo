#pragma once

#include "Data/test2.hpp"

#include "Interfaces/I_t4/I_t4.hpp"

namespace C_n {

class C_n;

class I_t4_i_p2 : public ::I_t4 {
public:
  C_n *composant;

  //! Default constructor
  I_t4_i_p2(C_n *comp);

  //! Destructor
  virtual ~I_t4_i_p2() noexcept;

  I_t4_i_p2() = delete;
  //! Copy constructor
  I_t4_i_p2(const I_t4_i_p2 &other) = delete;
  //! Move constructor
  I_t4_i_p2(I_t4_i_p2 &&other) = delete;
  // //! Copy assignment operator
  // I_t4& operator=(const I_t4 &other)=delete;
  // //! Move assignment operator
  // I_t4& operator=(I_t4 &&other) noexcept;

protected:
private:
};
};