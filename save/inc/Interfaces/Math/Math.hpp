#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include <functional>




class Caller;
class Math_caller;

class Fake;
class Math_fake;


class Math : public Interface
{
public:

  using MyCaller = Math_caller;
  using MyFake = Math_fake;

  Caller* c;

  virtual Caller* get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  Math();

  //! Destructor
  virtual ~Math() noexcept;

  // //! Copy assignment operator
  // Math& operator=(const Math &other){}

  // //! Move assignment operator
  // Math& operator=(Math &&other) noexcept{}
  virtual int add(int a,int b)=0;
  virtual int time(int a,int b)=0;
  virtual int sub(int a,int b)=0;
  virtual int div(int a,int b)=0;
  virtual int power(int a,int b)=0;
  virtual int mod(int a,int b)=0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////


protected:

private:
};

std::function<Interface*(std::ostream&,std::istream&)> build_fake(Math* t);
