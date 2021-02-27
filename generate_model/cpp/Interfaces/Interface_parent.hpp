#pragma once

namespace CompoMe {

class Caller_stream;
class Caller_dbus;
class Caller_json;

class Interface {
public:
  Interface();
  virtual ~Interface();
  virtual Caller_stream *get_caller_stream();
  virtual Caller_dbus *get_caller_dbus();
  virtual Caller_json *get_caller_json();
  virtual bool is_fake() { return false; };
};

} // namespace CompoMe
