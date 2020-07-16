#pragma once

#include "Interfaces/test/test.hpp"

#include "Interfaces/test_p/test_p_caller_stream.hpp"

#include <string>

class test_caller_stream : public test_p_caller_stream {
private:
  test &comp;

public:
  test_caller_stream(test &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool f7(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f8(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f9(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f10(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f11(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f12(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool get_a(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
  bool set_a(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);

  bool get_b(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
  bool set_b(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
};
