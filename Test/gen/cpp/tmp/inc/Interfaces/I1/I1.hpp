#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"



class I1 : public Interface
{
public:
  //! Default constructor
  I1(){}

  //! Copy constructor
  I1(const I1 &other){}

  //! Move constructor
  I1(I1 &&other) noexcept{}

  //! Destructor
  virtual ~I1() noexcept{}

  // //! Copy assignment operator
  // I1& operator=(const I1 &other){}

  // //! Move assignment operator
  // I1& operator=(I1 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////


protected:

private:
};