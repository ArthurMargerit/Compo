#pragma once

#include "Interfaces/Car/Gate/Locker/Locker.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace Car {

namespace Gate {

class Locker_caller_stream : public CompoMe::Caller_stream {
private:
  Car::Gate::Locker &comp;

public:
  Locker_caller_stream(Car::Gate::Locker &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool open_window(CompoMe::Function_stream_recv &is,
                   CompoMe::Return_stream_send &os);

  bool close_window(CompoMe::Function_stream_recv &is,
                    CompoMe::Return_stream_send &os);

  bool state(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
};

} // namespace Gate

} // namespace Car
