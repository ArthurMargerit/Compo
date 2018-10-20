#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"



class I2 : public Interface
{
public:
  //! Default constructor
  I2(){}

  //! Copy constructor
  I2(const I2 &other){}

  //! Move constructor
  I2(I2 &&other) noexcept{}

  //! Destructor
  virtual ~I2() noexcept{}

  // //! Copy assignment operator
  // I2& operator=(const I2 &other){}

  // //! Move assignment operator
  // I2& operator=(I2 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////


protected:

private:
};