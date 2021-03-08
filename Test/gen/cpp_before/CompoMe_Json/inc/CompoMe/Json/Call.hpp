#pragma once

#include "Interfaces/Caller_json.hpp"
#include "json.hpp"
#include <map>

namespace CompoMe {
namespace Json {
namespace Tools {
using call_result = std::pair<bool, nlohmann::json>;

call_result call(Caller_json *c, nlohmann::json &cmd);
call_result call(std::map<std::string, Caller_json *> &c, nlohmann::json &cmd);
call_result call(std::map<std::string, std::map<std::string, Caller_json *>> &c,
                 nlohmann::json &cmd);
} // namespace Tools
} // namespace Json
} // namespace CompoMe
