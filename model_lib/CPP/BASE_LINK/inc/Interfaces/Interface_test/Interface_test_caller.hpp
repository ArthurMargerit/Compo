#pragma once

#include <istream>
#include <ostream>

#include "Interfaces/Caller.hpp"
#include "Interfaces/Interface_test/Interface_test.hpp"

class Interface_test_caller : public Caller {
private:
  Interface_test &comp;

public:
  Interface_test_caller(Interface_test &pcomp);

  bool call(Function_stream &is, Return_stream &os);

private:
  void f1(Function_stream &is, Return_stream &os);

  void f2(Function_stream &is, Return_stream &os);

  void f3(Function_stream &is, Return_stream &os);

  void get_a(Function_stream &is, Return_stream &os);
  void set_a(Function_stream &is, Return_stream &os);

  void get_b(Function_stream &is, Return_stream &os);
  void set_b(Function_stream &is, Return_stream &os);
};
