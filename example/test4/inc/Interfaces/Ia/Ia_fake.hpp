#pragma once

#include "Data/Base.hpp"

#include "Interfaces/Ia/Ia.hpp"

#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Ia_fake : public Ia, private Fake {
public:
  // constructor
  Ia_fake(Function_stream &out, Return_stream &in);

  //! Destructor
  virtual ~Ia_fake() noexcept;

  static Interface *Build_func(Function_stream &os, Return_stream &is) {
    return (Ia *)new Ia_fake(os, is);
  }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual i ping(vec<i> p);

  virtual i pp(vec<i> p1, vec<d> p2);

  virtual vec<i> p();

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual vec<i> get_v1() const;
  virtual void set_v1(const vec<i> v1);

  virtual vec<d> get_v2() const;
  virtual void set_v2(const vec<d> v2);

protected:
private:
};
