#pragma once

#include <istream>
#include <ostream>

#include "Interfaces/Caller.hpp"
#include "Interfaces/I2/I2.hpp"

class I2_caller : public Caller {
private:
  I2 &comp;

public:
  I2_caller(I2 &pcomp);

  bool call(Function_stream &is, Return_stream &os);

private:
};
