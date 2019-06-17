#pragma once

#include "Interfaces/Ia/Ia.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class Ia_caller : public Caller {
private:
  Ia &comp;

public:
  Ia_caller(Ia &pcomp);

  bool call(Function_stream &is, Return_stream &os);
  virtual bool call(std::string &name_function, Function_stream &is,
                    Return_stream &os);

private:
  void ping(Function_stream &is, Return_stream &os);

  void pp(Function_stream &is, Return_stream &os);

  void p(Function_stream &is, Return_stream &os);

  void get_v1(Function_stream &is, Return_stream &os);
  void set_v1(Function_stream &is, Return_stream &os);

  void get_v2(Function_stream &is, Return_stream &os);
  void set_v2(Function_stream &is, Return_stream &os);
};
