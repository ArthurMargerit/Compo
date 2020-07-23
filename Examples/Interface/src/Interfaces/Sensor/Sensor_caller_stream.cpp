
#include "Interfaces/Sensor/Sensor_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Sensor_caller_stream::Sensor_caller_stream(Sensor &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Sensor_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool Sensor_caller_stream::call(std::string &name_function,
                                CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("get_value"):
    result = this->get_value(is, os);
    break;

  case str2int("get_range"):
    result = this->get_range(is, os);
    break;
  };

  return result;
}

bool Sensor_caller_stream::get_value(CompoMe::Function_stream_recv &is,
                                     CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.get_value();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Sensor_caller_stream::get_range(CompoMe::Function_stream_recv &is,
                                     CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.get_range();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}
