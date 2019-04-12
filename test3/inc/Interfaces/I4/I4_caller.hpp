#pragma once

#include <istream>
#include <ostream>

#include "Interfaces/Caller.hpp"
#include "Interfaces/I4/I4.hpp"

class I4_caller : public Caller {
private:
  I4 &comp;

public:
  I4_caller(I4 &pcomp);

  bool call(Function_stream &is, Return_stream &os);

private:
};
