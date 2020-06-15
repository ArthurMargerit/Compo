#pragma once

#include "Interfaces/Car/Gate/Window//Window.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

namespace Car {

namespace Gate {

class Window_caller : public Caller {
private:
  Car::Gate::Window &comp;

public:
  Window_caller(Car::Gate::Window &pcomp);
  bool call(Function_stream_recv &is, Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, Function_stream_recv &is,
            Return_stream_send &os) override;

private:
  bool lock(Function_stream_recv &is, Return_stream_send &os);

  bool unlock(Function_stream_recv &is, Return_stream_send &os);

  bool get_percent(Function_stream_recv &is, Return_stream_send &os);
  bool set_percent(Function_stream_recv &is, Return_stream_send &os);
};

} // namespace Gate

} // namespace Car
