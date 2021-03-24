#include "CompoMe/Json/Call.hpp"
#include "CompoMe/Log.hpp"
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

call_result call(std::map<std::string, Caller_json *> &c, nlohmann::json &cmd) {
  std::string l_inter_func = cmd["function"];

  auto l_pos = l_inter_func.find(".");
  if (l_pos == std::string::npos) {
    C_ERROR("wrong INTERFACE.FUNCTION");
    throw "Json Error";
  }

  std::string l_inter = l_inter_func.substr(0, l_pos);
  auto r = c.find(l_inter);
  if (r == c.end()) {
    C_ERROR("The interface ", l_inter, " is not available.");
    throw "Json Error";
  }

  std::string l_func = l_inter_func.substr(l_pos + 1);
  cmd["function"] = l_func;

  return call(r->second, cmd);
}

call_result call(std::map<std::string, std::map<std::string, Caller_json *>> &c,
                 nlohmann::json &cmd) {
  std::string l_comp_inter_func = cmd["function"];

  auto l_pos = l_comp_inter_func.find(".");
  if (l_pos == std::string::npos) {
    C_ERROR("wrong patern COMPONENT.INTERFACE.FUNCTION");
    throw "Json Error";
  }

  std::string l_comp = l_comp_inter_func.substr(0, l_pos);
  auto r = c.find(l_comp);
  if (r == c.end()) {
    C_ERROR("The component ", l_comp, " is not available.");
    throw "Json Error";
  }
  std::string l_inter_func = l_comp_inter_func.substr(l_pos + 1);
  cmd["function"] = l_inter_func;

  return call(r->second, cmd);
}
} // namespace Tools
} // namespace Json
} // namespace CompoMe
