#pragma once

#include "Interfaces/I_t3/I_t3.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class I_t3_caller : public Caller {
private:
  I_t3 &comp;

public:
  I_t3_caller(I_t3 &pcomp);

  bool call(Function_stream &is, Return_stream &os);
  virtual bool call(std::string &name_function, Function_stream &is,
                    Return_stream &os);

private:
};
