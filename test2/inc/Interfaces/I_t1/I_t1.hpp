#pragma once

#include "Data/test2.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

#include "Data/Struct_A.hpp"

#include "Data/Struct_B.hpp"

#include "Data/Struct_D.hpp"

#include "Data/Struct_C.hpp"

class Caller;
class I_t1_caller;

class Fake;
class I_t1_fake;

class I_t1 : public Interface {
public:
  using MyCaller = I_t1_caller;
  using MyFake = I_t1_fake;

  virtual Caller *get_caller();

  //! Default constructor
  I_t1();

  //! Destructor
  virtual ~I_t1() noexcept;

  // //! Copy assignment operator
  // I_t1& operator=(const I_t1 &other){}

  // //! Move assignment operator
  // I_t1& operator=(I_t1 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  // sa //
  virtual A get_sa() const { return sa; }

  virtual void set_sa(const A sa) { this->sa = sa; }
  // sb //
  virtual B get_sb() const { return sb; }

  virtual void set_sb(const B sb) { this->sb = sb; }
  // sc //
  virtual C get_sc() const { return sc; }

  virtual void set_sc(const C sc) { this->sc = sc; }
  // sd //
  virtual D get_sd() const { return sd; }

  virtual void set_sd(const D sd) { this->sd = sd; }

protected:
private:
  Caller *c;
  A sa;
  B sb;
  C sc;
  D sd;
};

Build_fake_F get_build_fake(I_t1 *t);
