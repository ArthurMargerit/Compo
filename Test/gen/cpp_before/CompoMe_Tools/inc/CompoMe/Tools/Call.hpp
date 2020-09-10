#pragma once

#include "Interfaces/Caller_stream.hpp"
#include <map>
#include <string>

namespace CompoMe {
namespace Tools {
  std::pair<bool, std::string> call(Caller_stream *c,std::string cmd);

std::pair<bool, std::string> call(std::map<std::string, Caller_stream *> &c,
                                  std::string cmd);

std::pair<bool, std::string>
call(std::map<std::string, std::map<std::string, Caller_stream *>> &c,
     std::string cmd);

} // namespace Tools
} // namespace CompoMe
