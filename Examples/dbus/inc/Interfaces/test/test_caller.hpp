#pragma once

#include "Interfaces/test//test.hpp"

#include "Interfaces/test_p/test_p_caller.hpp"

#include <string>

class test_caller : public test_p_caller {
private:
  test &comp;

public:
  test_caller(test &pcomp);
  bool call(Function_stream_recv &is, Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, Function_stream_recv &is,
            Return_stream_send &os) override;

private:
  bool f7(Function_stream_recv &is, Return_stream_send &os);

  bool f8(Function_stream_recv &is, Return_stream_send &os);

  bool f9(Function_stream_recv &is, Return_stream_send &os);

  bool f10(Function_stream_recv &is, Return_stream_send &os);

  bool get_a(Function_stream_recv &is, Return_stream_send &os);
  bool set_a(Function_stream_recv &is, Return_stream_send &os);

  bool get_b(Function_stream_recv &is, Return_stream_send &os);
  bool set_b(Function_stream_recv &is, Return_stream_send &os);
};
