#pragma once

#include <istream>
#include <ostream>

#include "Interfaces/Caller.hpp"
#include "Interfaces/I1/I1.hpp"

class I1_caller : public Caller {
private:
  I1 &comp;

public:
  I1_caller(I1 &pcomp);

  bool call(Function_stream &is, Return_stream &os);

private:
  void add(Function_stream &is, Return_stream &os);

  void get_a(Function_stream &is, Return_stream &os);
  void set_a(Function_stream &is, Return_stream &os);
};
