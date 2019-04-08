#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class Hello_Interface_caller;

class Fake;
class Hello_Interface_fake;

class Hello_Interface : public Interface {
public:
  using MyCaller = Hello_Interface_caller;
  using MyFake = Hello_Interface_fake;

  Caller *c;

  virtual Caller *get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  Hello_Interface();

  //! Destructor
  virtual ~Hello_Interface() noexcept;

  // //! Copy assignment operator
  // Hello_Interface& operator=(const Hello_Interface &other){}

  // //! Move assignment operator
  // Hello_Interface& operator=(Hello_Interface &&other) noexcept{}
  virtual void hello_word() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};

std::function<Fake *(Function_stream &, Return_stream &)>
build_fake(Hello_Interface *t);
