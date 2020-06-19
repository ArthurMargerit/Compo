#pragma once

#include "Interfaces/Calculator//Calculator.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class Calculator_caller : public Caller {
private:
  Calculator &comp;

public:
  Calculator_caller(Calculator &pcomp);
  bool call(Function_stream_recv &is, Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, Function_stream_recv &is,
            Return_stream_send &os) override;

private:
  bool add(Function_stream_recv &is, Return_stream_send &os);

  bool sub(Function_stream_recv &is, Return_stream_send &os);

  bool time(Function_stream_recv &is, Return_stream_send &os);

  bool div(Function_stream_recv &is, Return_stream_send &os);
};
