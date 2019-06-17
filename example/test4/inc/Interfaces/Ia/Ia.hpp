#pragma once

#include "Data/Base.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class Ia_caller;

class Fake;
class Ia_fake;

class Ia : public Interface {
public:
  using MyCaller = Ia_caller;
  using MyFake = Ia_fake;

  virtual Caller *get_caller();

  //! Default constructor
  Ia();

  //! Destructor
  virtual ~Ia() noexcept;

  // //! Copy assignment operator
  // Ia& operator=(const Ia &other){}

  // //! Move assignment operator
  // Ia& operator=(Ia &&other) noexcept{}
  virtual i ping(vec<i> p) = 0;
  virtual i pp(vec<i> p1, vec<d> p2) = 0;
  virtual vec<i> p() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  // v1 //
  virtual vec<i> get_v1() const { return v1; }

  virtual void set_v1(const vec<i> v1) { this->v1 = v1; }
  // v2 //
  virtual vec<d> get_v2() const { return v2; }

  virtual void set_v2(const vec<d> v2) { this->v2 = v2; }

protected:
private:
  Caller *c;
  vec<i> v1;
  vec<d> v2;
};

Build_fake_F get_build_fake(Ia *t);
