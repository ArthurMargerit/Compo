#pragma once

#include <istream>
#include <ostream>

#include "Interfaces/Caller.hpp"
#include "Interfaces/Hello_Interface/Hello_Interface.hpp"

class Hello_Interface_caller : public Caller {
private:
  Hello_Interface &comp;

public:
  Hello_Interface_caller(Hello_Interface &pcomp);

  bool call(Function_stream &is, Return_stream &os);

private:
  void hello_word(Function_stream &is, Return_stream &os);
};
