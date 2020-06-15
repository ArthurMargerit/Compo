#pragma once

#include "Interfaces/Sensor//Sensor.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class Sensor_caller : public Caller {
private:
  Sensor &comp;

public:
  Sensor_caller(Sensor &pcomp);
  bool call(Function_stream_recv &is, Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, Function_stream_recv &is,
            Return_stream_send &os) override;

private:
  bool get_value(Function_stream_recv &is, Return_stream_send &os);

  bool get_range(Function_stream_recv &is, Return_stream_send &os);
};
