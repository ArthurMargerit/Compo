#pragma once

#include <istream>
#include <ostream>

#include "Interfaces/Caller.hpp"
#include "Interfaces/Log_i/Log_i.hpp"

class Log_i_caller : public Caller {
private:
  Log_i &comp;

public:
  Log_i_caller(Log_i &pcomp);

  bool call(Function_stream &is, Return_stream &os);

private:
  void info(Function_stream &is, Return_stream &os);

  void debug(Function_stream &is, Return_stream &os);

  void warning(Function_stream &is, Return_stream &os);

  void error(Function_stream &is, Return_stream &os);

  void log(Function_stream &is, Return_stream &os);
};
