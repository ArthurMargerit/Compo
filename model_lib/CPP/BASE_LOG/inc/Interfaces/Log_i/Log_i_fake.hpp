#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Log_i/Log_i.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Log_i_fake : public Log_i, public Fake {
public:
  //! Default constructor
  Log_i_fake(Function_stream &out, Return_stream &in);

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new Log_i_fake(os, is);
  }

  //! Destructor
  virtual ~Log_i_fake() noexcept;
  virtual void info(String mess);
  virtual void debug(String mess);
  virtual void warning(String mess);
  virtual void error(String mess);
  virtual void log(Log_s mess);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
  Function_stream &o;
  Return_stream &i;
};
