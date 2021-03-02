
#include "Interfaces/Sensor_v2/Sensor_v2_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"
#include <string>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Sensor_v2_caller_stream::Sensor_v2_caller_stream(Sensor_v2 &pcomp)
    : Sensor_caller_stream(pcomp), comp(pcomp) {
  return;
}

bool Sensor_v2_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool Sensor_v2_caller_stream::call(std::string &name_function,
                                   CompoMe::Function_stream_recv &is,
                                   CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("add_offset"):
    result = this->add_offset(is, os);
    break;

  default:
    return Sensor_caller_stream::call(name_function, is, os);
    break;
  };

  return result;
}

bool Sensor_v2_caller_stream::add_offset(CompoMe::Function_stream_recv &is,
                                         CompoMe::Return_stream_send &os) {

  double l_offset;
  is >> l_offset;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.add_offset(l_offset);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}
