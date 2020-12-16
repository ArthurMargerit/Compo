#pragma once

#include "Interfaces/Car/Gate/Window/Window.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace Car {

namespace Gate {

class Window_caller_stream : public CompoMe::Caller_stream {
private:
  Car::Gate::Window &comp;

public:
  Window_caller_stream(Car::Gate::Window &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool lock(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool unlock(CompoMe::Function_stream_recv &is,
              CompoMe::Return_stream_send &os);

  bool get_percent(CompoMe::Function_stream_recv &is,
                   CompoMe::Return_stream_send &os);
  bool set_percent(CompoMe::Function_stream_recv &is,
                   CompoMe::Return_stream_send &os);
};

} // namespace Gate

} // namespace Car
