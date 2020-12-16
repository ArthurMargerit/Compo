#pragma once

#include "Interfaces/Calc_I/Calc_I.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

class Calc_I_caller_stream : public CompoMe::Caller_stream {
private:
  Calc_I &comp;

public:
  Calc_I_caller_stream(Calc_I &pcomp);
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
