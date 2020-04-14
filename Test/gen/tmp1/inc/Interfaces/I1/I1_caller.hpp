#pragma once

#include "Interfaces/I1//I1.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class I1_caller : public Caller {
private:
  I1 &comp;

public:
  I1_caller(I1 &pcomp);
  bool call(Function_stream &is, Return_stream &os) override;

protected:
  bool call(std::string &name_function, Function_stream &is,
            Return_stream &os) override;

private:
  bool f(Function_stream &is, Return_stream &os);

  bool f1(Function_stream &is, Return_stream &os);

  bool f2(Function_stream &is, Return_stream &os);

  bool f3(Function_stream &is, Return_stream &os);

  bool f4(Function_stream &is, Return_stream &os);

  bool f5(Function_stream &is, Return_stream &os);
};
