#pragma once

#include "Interfaces/Car/Reporter/Reporter.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace Car {

class Reporter_caller_stream : public CompoMe::Caller_stream {
private:
  Car::Reporter &comp;

public:
  Reporter_caller_stream(Car::Reporter &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool send_err(CompoMe::Function_stream_recv &is,
                CompoMe::Return_stream_send &os);

  bool send_info(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);
};

} // namespace Car
