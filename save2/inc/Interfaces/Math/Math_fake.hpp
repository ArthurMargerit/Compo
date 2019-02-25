#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Math/Math.hpp"
#include "Interfaces/Fake.hpp"

#include <ostream>
#include <istream>

class Math_fake : public Math, public Fake
{
public:
  //! Default constructor
  Math_fake(std::ostream& out, std::istream& in);

  static
    Fake* Build_func(std::ostream& os, std::istream& is)
  {
    return new Math_fake(os,is);
  }

  //! Destructor
  virtual ~Math_fake() noexcept;
  virtual
  int add(int a,int b);
  virtual
  int time(int a,int b);
  virtual
  int sub(int a,int b);
  virtual
  int div(int a,int b);
  virtual
  int power(int a,int b);
  virtual
  int mod(int a,int b);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////


protected:

private:
    std::ostream& o;
  std::istream& i;
};

