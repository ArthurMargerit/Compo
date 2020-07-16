#pragma once

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"
namespace CompoMe {

class Fake_stream {

public:
  Fake_stream(CompoMe::Function_stream_send &, CompoMe::Return_stream_recv &);
  virtual ~Fake_stream();

  CompoMe::Return_stream_recv &get_i() const { return a_i; }
  CompoMe::Function_stream_send &get_o() const { return a_o; }

private:
  CompoMe::Function_stream_send &a_o;
  CompoMe::Return_stream_recv &a_i;
};

} // namespace CompoMe
