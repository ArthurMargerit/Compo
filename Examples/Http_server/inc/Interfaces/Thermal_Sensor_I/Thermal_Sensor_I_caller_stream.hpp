#pragma once

#include "Interfaces/Thermal_Sensor_I/Thermal_Sensor_I.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

class Thermal_Sensor_I_caller_stream : public CompoMe::Caller_stream {
private:
  Thermal_Sensor_I &comp;

public:
  Thermal_Sensor_I_caller_stream(Thermal_Sensor_I &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

  void introspection(std::ostream &ss) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool get_temperature(CompoMe::Function_stream_recv &is,
                       CompoMe::Return_stream_send &os);

  bool get_ofset(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);
  bool set_ofset(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);
};
