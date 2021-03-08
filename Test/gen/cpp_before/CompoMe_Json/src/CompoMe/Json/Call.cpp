#include "CompoMe/Json/Call.hpp"
#include "Interfaces/Function_json_recv.hpp"
#include "Interfaces/Return_json_send.hpp"

namespace CompoMe {
namespace Json {
namespace Tools {
namespace {
class Fs : public CompoMe::Function_json_recv {
  void pull() override {}
  void end() override {}
};

class Rs : public CompoMe::Return_json_send {
  void send() override {}
  void start() override {}
};
} // Namespace

call_result call(Caller_json *c, nlohmann::json &cmd) {
  if (c == nullptr) {
    return {false, "Caller_json is nullptr, then no call can be perform"};
  }
  Fs f;
  Rs r;
  f.set_data(cmd);
  bool l_result = c->call(f, r);
  return {l_result, (l_result) ? r.get_data() : "... Wrong form ..."};
}

// call_result call(std::map<std::string, Caller_json *> &c, nlohmann::json
// &cmd) {
// }
// call_result call(std::map<std::string, std::map<std::string, Caller_json *>>
// &c,
//                  nlohmann::json &cmd) {}
} // namespace Tools
} // namespace Json
} // namespace CompoMe
