#pragma once

#include "Interfaces/Car/Gate/Locker//Locker.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

namespace Car {

namespace Gate {

class Locker_caller : public Caller {
private:
  Car::Gate::Locker &comp;

public:
  Locker_caller(Car::Gate::Locker &pcomp);
  bool call(Function_stream_recv &is, Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, Function_stream_recv &is,
            Return_stream_send &os) override;

private:
  bool open_window(Function_stream_recv &is, Return_stream_send &os);

  bool close_window(Function_stream_recv &is, Return_stream_send &os);

  bool state(Function_stream_recv &is, Return_stream_send &os);
};

} // namespace Gate

} // namespace Car
