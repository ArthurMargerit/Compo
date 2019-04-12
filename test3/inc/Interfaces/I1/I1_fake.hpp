#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I1/I1.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I1_fake : public I1, public Fake {
public:
  //! Default constructor
  I1_fake(Function_stream &out, Return_stream &in);

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new I1_fake(os, is);
  }

  //! Destructor
  virtual ~I1_fake() noexcept;
  virtual int add(int x, int y);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual int get_a() const;
  virtual void set_a(const int a);

protected:
private:
  Function_stream &o;
  Return_stream &i;
  int a;
};
