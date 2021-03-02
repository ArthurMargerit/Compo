#pragma once

#include "Interfaces/Sensor_v2/Sensor_v2.hpp"

#include "Interfaces/Sensor/Sensor_caller_stream.hpp"

#include <string>

class Sensor_v2_caller_stream : public Sensor_caller_stream {
private:
  Sensor_v2 &comp;

public:
  Sensor_v2_caller_stream(Sensor_v2 &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool add_offset(CompoMe::Function_stream_recv &is,
                  CompoMe::Return_stream_send &os);
};
