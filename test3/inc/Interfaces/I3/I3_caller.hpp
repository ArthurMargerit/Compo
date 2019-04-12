#pragma once

#include <istream>
#include <ostream>

#include "Interfaces/Caller.hpp"
#include "Interfaces/I3/I3.hpp"

class I3_caller : public Caller {
private:
  I3 &comp;

public:
  I3_caller(I3 &pcomp);

  bool call(Function_stream &is, Return_stream &os);

private:
};
