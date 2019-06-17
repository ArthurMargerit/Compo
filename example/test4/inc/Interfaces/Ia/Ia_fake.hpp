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

  virtual int_tt ping(vec<int_tt> p);

  virtual int_tt pp(vec<int_tt> p1, vec<d> p2);

  virtual vec<int_tt> p();

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual vec<int_tt> get_v1() const;
  virtual void set_v1(const vec<int_tt> v1);

  virtual vec<d> get_v2() const;
  virtual void set_v2(const vec<d> v2);

protected:
private:
};
