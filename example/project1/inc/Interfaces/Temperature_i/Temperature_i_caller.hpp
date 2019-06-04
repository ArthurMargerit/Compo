#pragma once

#include "Interfaces/Temperature_i/Temperature_i.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class Temperature_i_caller : public Caller {
private:
  Temperature_i &comp;

public:
  Temperature_i_caller(Temperature_i &pcomp);

  bool call(Function_stream &is, Return_stream &os);
  virtual bool call(std::string &name_function, Function_stream &is,
                    Return_stream &os);

private:
  void get(Function_stream &is, Return_stream &os);
};
