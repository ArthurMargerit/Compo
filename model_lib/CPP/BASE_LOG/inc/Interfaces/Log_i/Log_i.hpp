#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class Log_i_caller;

class Fake;
class Log_i_fake;

class Log_i : public Interface {
public:
  using MyCaller = Log_i_caller;
  using MyFake = Log_i_fake;

  Caller *c;

  virtual Caller *get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  Log_i();

  //! Destructor
  virtual ~Log_i() noexcept;

  // //! Copy assignment operator
  // Log_i& operator=(const Log_i &other){}

  // //! Move assignment operator
  // Log_i& operator=(Log_i &&other) noexcept{}
  virtual void info(String mess) = 0;
  virtual void debug(String mess) = 0;
  virtual void warning(String mess) = 0;
  virtual void error(String mess) = 0;
  virtual void log(Log_s mess) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(Log_i *t);
