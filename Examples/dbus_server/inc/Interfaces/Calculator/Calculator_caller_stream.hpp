#pragma once

#include "Interfaces/Calculator/Calculator.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

class Calculator_caller_stream : public CompoMe::Caller_stream {
private:
  Calculator &comp;

public:
  Calculator_caller_stream(Calculator &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool add(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool sub(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool time(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool div(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);
};
