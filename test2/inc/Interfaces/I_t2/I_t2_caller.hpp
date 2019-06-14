#pragma once

#include "Interfaces/I_t2/I_t2.hpp"

#include "Interfaces/I_t1/I_t1_caller.hpp"

#include <string>

class I_t2_caller : public I_t1_caller {
private:
  I_t2 &comp;

public:
  I_t2_caller(I_t2 &pcomp);

  bool call(Function_stream &is, Return_stream &os);
  virtual bool call(std::string &name_function, Function_stream &is,
                    Return_stream &os);

private:
};
