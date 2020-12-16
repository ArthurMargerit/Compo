
#include "Interfaces/Thermal_Sensor_I/Thermal_Sensor_I_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Thermal_Sensor_I_caller_stream::Thermal_Sensor_I_caller_stream(
    Thermal_Sensor_I &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Thermal_Sensor_I_caller_stream::call(CompoMe::Function_stream_recv &is,
                                          CompoMe::Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool Thermal_Sensor_I_caller_stream::call(std::string &name_function,
                                          CompoMe::Function_stream_recv &is,
                                          CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("get_temperature"):
    result = this->get_temperature(is, os);
    break;

  case str2int("get_ofset"):
    result = this->get_ofset(is, os);
    break;

  case str2int("set_ofset"):
    result = this->set_ofset(is, os);
    break;
  };

  return result;
}

bool Thermal_Sensor_I_caller_stream::get_temperature(
    CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.get_temperature();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Thermal_Sensor_I_caller_stream::get_ofset(
    CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os) {
  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {
    os << this->comp.get_ofset();
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Thermal_Sensor_I_caller_stream::set_ofset(
    CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os) {
  double set_val;
  is >> set_val;

  char l = is.get();
  if (l != ')') {
    return false;
  }

  try {
    this->comp.set_ofset(set_val);
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

void Thermal_Sensor_I_caller_stream::introspection(std::ostream &ss) {

  ss << "- Thermal_Sensor_I"
     << "\n";

  ss << "\t double get_temperature("

     << ")\n";
}
