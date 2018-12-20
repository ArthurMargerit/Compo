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
  Math_fake(std::ostream& out, std::istream& in):o(out),i(in)
            {

            }

  static

  Interface* Build_func(std::ostream& os, std::istream& is)
  {
    return new Math_fake(os,is);
  }

  //! Destructor
  virtual ~Math_fake() noexcept{}
  virtual
  int add(int a,int b)
    {
      o << "add("
                
        << a
        << ","
           
      
        << b
      
        << ")"
        << std::endl;

      
      int ri;
      i >> ri;
      return ri;
      
    }
  virtual
  int time(int a,int b)
    {
      o << "time("
                
        << a
        << ","
           
      
        << b
      
        << ")"
        << std::endl;

      
      int ri;
      i >> ri;
      return ri;
      
    }
  virtual
  int sub(int a,int b)
    {
      o << "sub("
                
        << a
        << ","
           
      
        << b
      
        << ")"
        << std::endl;

      
      int ri;
      i >> ri;
      return ri;
      
    }
  virtual
  int div(int a,int b)
    {
      o << "div("
                
        << a
        << ","
           
      
        << b
      
        << ")"
        << std::endl;

      
      int ri;
      i >> ri;
      return ri;
      
    }
  virtual
  int power(int a,int b)
    {
      o << "power("
                
        << a
        << ","
           
      
        << b
      
        << ")"
        << std::endl;

      
      int ri;
      i >> ri;
      return ri;
      
    }
  virtual
  int mod(int a,int b)
    {
      o << "mod("
                
        << a
        << ","
           
      
        << b
      
        << ")"
        << std::endl;

      
      int ri;
      i >> ri;
      return ri;
      
    }

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////


protected:

private:
    std::ostream& o;
  std::istream& i;
};

