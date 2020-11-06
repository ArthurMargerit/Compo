#include "CompoMe/Tools/Call.hpp"
#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace CompoMe {
namespace Tools {
namespace {

class Fs : public CompoMe::Function_stream_recv {
  std::stringstream s;

public:
  Fs() {}
  virtual ~Fs() {}

  void set_str(std::string p_str) { this->s.str(p_str); }
  void pull() {}

  void end() {}

  void reset() { this->s = std::stringstream(); }

  std::istream &get_si() { return s; }
};

class Rs : public CompoMe::Return_stream_send {
  std::stringstream s;

public:
  Rs() {}
  virtual ~Rs() {}

  std::string get_str() { return this->s.str(); }
  void start() { this->s.str(""); }
  void send() {}
  std::ostream &get_so() { return s; }
};
} // namespace

call_result call(Caller_stream *c, std::string cmd) {
  if (c == nullptr) {
    return {false, "Caller_stream is nullptr, then no call can be perform"};
  }

  Fs f;
  Rs r;

  f.reset();
  f.set_str(cmd);
  bool l_result = c->call(f, r);
  return {l_result, (l_result) ? r.get_str() : "... Wrong form ..."};
}

call_result call(std::map<std::string, Caller_stream *> &c, std::string cmd) {
  auto l_pos_i = cmd.find(".");

  if (l_pos_i == std::string::npos) {
    return {false, "No Interface Specified."};
  }

  auto l_interface = std::string(cmd, 0, l_pos_i);
  if (c.find(l_interface) == c.end()) {
    return {false, "No Interface " + l_interface};
  }

  auto sub_cmd = std::string(cmd, l_pos_i + 1, cmd.length());
  return call(c[l_interface], sub_cmd);
}

call_result
call(std::map<std::string, std::map<std::string, Caller_stream *>> &c,
     std::string cmd) {
  auto l_pos_c = cmd.find(".");

  if (l_pos_c == std::string::npos) {
    return {false, "No Components Specified."};
  }

  auto l_component = std::string(cmd, 0, l_pos_c);
  if (c.find(l_component) == c.end()) {
    return {false, "No Components " + l_component};
  }

  auto sub_cmd = std::string(cmd, l_pos_c + 1, cmd.length());
  return call(c[l_component], sub_cmd);
}
} // namespace Tools
} // namespace CompoMe
