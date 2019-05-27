#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Interface_test/Interface_test.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Interface_test_fake : public Interface_test, public Fake {
public:
  //! Default constructor
  Interface_test_fake(Function_stream &out, Return_stream &in);

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new Interface_test_fake(os, is);
  }

  //! Destructor
  virtual ~Interface_test_fake() noexcept;
  virtual int f1(int p1, int p2, int p3);
  virtual int f2(int p1, int p2, int p3);
  virtual int f3(int p1, int p2, int p3);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual int get_a() const;
  virtual void set_a(const int a);
  virtual int get_b() const;
  virtual void set_b(const int b);

protected:
private:
  Function_stream &o;
  Return_stream &i;
  int a;
  int b;
};
