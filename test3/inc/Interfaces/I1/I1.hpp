#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class I1_caller;

class Fake;
class I1_fake;

class I1 : public Interface {
public:
  using MyCaller = I1_caller;
  using MyFake = I1_fake;

  Caller *c;

  virtual Caller *get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  I1();

  //! Destructor
  virtual ~I1() noexcept;

  // //! Copy assignment operator
  // I1& operator=(const I1 &other){}

  // //! Move assignment operator
  // I1& operator=(I1 &&other) noexcept{}
  virtual int add(int x, int y) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual int get_a() const { return a; }

  virtual void set_a(const int a) { this->a = a; }

protected:
private:
  int a;
};

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(I1 *t);
