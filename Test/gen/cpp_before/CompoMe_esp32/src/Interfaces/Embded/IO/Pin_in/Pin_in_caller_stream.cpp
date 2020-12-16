
#include "Interfaces/Embded/IO/Pin_in/Pin_in_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace Embded {

namespace IO {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Pin_in_caller_stream::Pin_in_caller_stream(Pin_in &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Pin_in_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool Pin_in_caller_stream::call(std::string &name_function,
                                CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("get_state"):
    result = this->get_state(is, os);
    break;

  case str2int("set_state"):
    result = this->set_state(is, os);
    break;
  };

  return result;
}

bool Pin_in_caller_stream::get_state(CompoMe::Function_stream_recv &is,
                                     CompoMe::Return_stream_send &os) {
  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {
    os << this->comp.get_state();
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Pin_in_caller_stream::set_state(CompoMe::Function_stream_recv &is,
                                     CompoMe::Return_stream_send &os) {
  Embded::IO::Pin_State set_val;
  is >> set_val;

  char l = is.get();
  if (l != ')') {
    return false;
  }

  try {
    this->comp.set_state(set_val);
  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace IO

} // namespace Embded
