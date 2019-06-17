#pragma once

#include "Interfaces/I_t4/I_t4.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class I_t4_caller : public Caller {
private:
  I_t4 &comp;

public:
  I_t4_caller(I_t4 &pcomp);

  bool call(Function_stream &is, Return_stream &os);
  virtual bool call(std::string &name_function, Function_stream &is,
                    Return_stream &os);

private:
};
