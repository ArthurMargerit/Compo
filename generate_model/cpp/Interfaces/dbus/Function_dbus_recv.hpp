#pragma once
#include <dbus/dbus.h>
#include <string>

namespace CompoMe {
class Struct;

class Serialization_context_import;

class Function_dbus_recv {
public:
  virtual DBusMessageIter &get_si() = 0;
  virtual void pull() = 0;
  virtual void end() = 0;
  virtual std::string get_function() = 0;
  virtual Serialization_context_import &get_ctx() = 0;
};

void import_struct(Function_dbus_recv &s, Struct &e);

} // namespace CompoMe

template <typename T>
CompoMe::Function_dbus_recv &operator>>(CompoMe::Function_dbus_recv &s, T &e) {
  //  s.get_si() >> e;
  return s;
}
