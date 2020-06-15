#pragma once

#include "Interfaces/Information//Information.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class Information_caller : public Caller {
private:
  Information &comp;

public:
  Information_caller(Information &pcomp);
  bool call(Function_stream_recv &is, Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, Function_stream_recv &is,
            Return_stream_send &os) override;

private:
  bool get_name(Function_stream_recv &is, Return_stream_send &os);

  bool get_type(Function_stream_recv &is, Return_stream_send &os);

  bool get_location(Function_stream_recv &is, Return_stream_send &os);
};
