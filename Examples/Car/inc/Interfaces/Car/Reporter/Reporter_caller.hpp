#pragma once

#include "Interfaces/Car/Reporter//Reporter.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

namespace Car {

class Reporter_caller : public Caller {
private:
  Car::Reporter &comp;

public:
  Reporter_caller(Car::Reporter &pcomp);
  bool call(Function_stream_recv &is, Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, Function_stream_recv &is,
            Return_stream_send &os) override;

private:
  bool send_err(Function_stream_recv &is, Return_stream_send &os);

  bool send_info(Function_stream_recv &is, Return_stream_send &os);
};

} // namespace Car
