#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Hello_Interface/Hello_Interface.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Hello_Interface_fake : public Hello_Interface, public Fake {
public:
  //! Default constructor
  Hello_Interface_fake(Function_stream &out, Return_stream &in);

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new Hello_Interface_fake(os, is);
  }

  //! Destructor
  virtual ~Hello_Interface_fake() noexcept;
  virtual void hello_word();

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
  Function_stream &o;
  Return_stream &i;
};
