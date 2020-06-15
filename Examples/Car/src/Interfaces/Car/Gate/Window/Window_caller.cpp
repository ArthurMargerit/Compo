
#include "Interfaces/Car/Gate/Window/Window_caller.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace Car {

namespace Gate {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Window_caller::Window_caller(Window &pcomp) : Caller(), comp(pcomp) { return; }

bool Window_caller::call(Function_stream_recv &is, Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool Window_caller::call(std::string &name_function, Function_stream_recv &is,
                         Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("lock"):
    result = this->lock(is, os);
    break;

  case str2int("unlock"):
    result = this->unlock(is, os);
    break;

  case str2int("get_percent"):
    result = this->get_percent(is, os);
    break;

  case str2int("set_percent"):
    result = this->set_percent(is, os);
    break;
  };

  return result;
}

bool Window_caller::lock(Function_stream_recv &is, Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.lock();

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Window_caller::unlock(Function_stream_recv &is, Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.unlock();

  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Window_caller::get_percent(Function_stream_recv &is,
                                Return_stream_send &os) {
  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {
    os << this->comp.get_percent();
  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Window_caller::set_percent(Function_stream_recv &is,
                                Return_stream_send &os) {
  ui8 set_val;
  is >> set_val;

  char l = is.get();
  if (l != ')') {
    return false;
  }

  try {
    this->comp.set_percent(set_val);
  } catch (const Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace Gate

} // namespace Car
