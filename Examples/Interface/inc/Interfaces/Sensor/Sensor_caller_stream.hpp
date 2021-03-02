#pragma once

#include "Interfaces/Sensor/Sensor.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

class Sensor_caller_stream : public CompoMe::Caller_stream {
private:
  Sensor &comp;

public:
  Sensor_caller_stream(Sensor &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool get_value(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);

  bool get_range(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);
};
