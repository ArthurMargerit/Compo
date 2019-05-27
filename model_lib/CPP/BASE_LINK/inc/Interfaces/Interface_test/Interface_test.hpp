#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class Interface_test_caller;

class Fake;
class Interface_test_fake;

class Interface_test : public Interface {
public:
  using MyCaller = Interface_test_caller;
  using MyFake = Interface_test_fake;

  Caller *c;

  virtual Caller *get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  Interface_test();

  //! Destructor
  virtual ~Interface_test() noexcept;

  // //! Copy assignment operator
  // Interface_test& operator=(const Interface_test &other){}

  // //! Move assignment operator
  // Interface_test& operator=(Interface_test &&other) noexcept{}
  virtual int f1(int p1, int p2, int p3) = 0;
  virtual int f2(int p1, int p2, int p3) = 0;
  virtual int f3(int p1, int p2, int p3) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual int get_a() const { return a; }

  virtual void set_a(const int a) { this->a = a; }
  virtual int get_b() const { return b; }

  virtual void set_b(const int b) { this->b = b; }

protected:
private:
  int a;
  int b;
};

std::function<Fake *(Function_stream &, Return_stream &)>
build_fake(Interface_test *t);
