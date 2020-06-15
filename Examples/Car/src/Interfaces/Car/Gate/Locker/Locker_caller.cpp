
#include "Interfaces/Car/Gate/Locker/Locker_caller.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace Car {

namespace Gate {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Locker_caller::Locker_caller(Locker &pcomp) : Caller(), comp(pcomp) { return; }

bool Locker_caller::call(Function_stream_recv &is, Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool Locker_caller::call(std::string &name_function, Function_stream_recv &is,
                         Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("open_window"):
    result = this->open_window(is, os);
    break;

  case str2int("close_window"):
    result = this->close_window(is, os);
    break;

  case str2int("state"):
    result = this->state(is, os);
    break;
  };

  return result;
}

bool Locker_caller::open_window(Function_stream_recv &is,
                                Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.open_window();

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Locker_caller::close_window(Function_stream_recv &is,
                                 Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.close_window();

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Locker_caller::state(Function_stream_recv &is, Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.state();

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace Gate

} // namespace Car
