#pragma once

#include "Interfaces/Caller_stream.hpp"
#include <map>
#include <string>

namespace CompoMe {
namespace Tools {
using call_result = std::pair<bool, std::string>;
call_result call(Caller_stream *c, std::string cmd);
call_result call(std::map<std::string, Caller_stream *> &c, std::string cmd);
call_result call(std::map<std::string, std::map<std::string, Caller_stream *>> &c, std::string cmd);
} // namespace Tools
} // namespace CompoMe
