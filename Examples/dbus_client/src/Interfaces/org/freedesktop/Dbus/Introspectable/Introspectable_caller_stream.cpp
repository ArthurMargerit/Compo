
#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace org {

namespace freedesktop {

namespace Dbus {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Introspectable_caller_stream::Introspectable_caller_stream(
    Introspectable &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Introspectable_caller_stream::call(CompoMe::Function_stream_recv &is,
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

bool Introspectable_caller_stream::call(std::string &name_function,
                                        CompoMe::Function_stream_recv &is,
                                        CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("Introspect"):
    result = this->Introspect(is, os);
    break;
  };

  return result;
}

bool Introspectable_caller_stream::Introspect(CompoMe::Function_stream_recv &is,
                                              CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.Introspect();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace Dbus

} // namespace freedesktop

} // namespace org
