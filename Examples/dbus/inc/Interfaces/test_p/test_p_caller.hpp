#pragma once

#include "Interfaces/test_p//test_p.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class test_p_caller : public Caller {
private:
  test_p &comp;

public:
  test_p_caller(test_p &pcomp);
  bool call(Function_stream_recv &is, Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, Function_stream_recv &is,
            Return_stream_send &os) override;

private:
  bool f0(Function_stream_recv &is, Return_stream_send &os);

  bool f1(Function_stream_recv &is, Return_stream_send &os);

  bool f2(Function_stream_recv &is, Return_stream_send &os);

  bool f3(Function_stream_recv &is, Return_stream_send &os);

  bool f5(Function_stream_recv &is, Return_stream_send &os);

  bool f6(Function_stream_recv &is, Return_stream_send &os);
};
