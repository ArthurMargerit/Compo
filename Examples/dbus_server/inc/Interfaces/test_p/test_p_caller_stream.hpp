#pragma once

#include "Interfaces/test_p/test_p.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

class test_p_caller_stream : public CompoMe::Caller_stream {
private:
  test_p &comp;

public:
  test_p_caller_stream(test_p &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool f0(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f1(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f2(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f3(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f5(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f6(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);
};
