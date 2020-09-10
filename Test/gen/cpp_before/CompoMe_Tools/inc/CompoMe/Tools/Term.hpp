
#include <map>
#include <string>

namespace CompoMe {
class Caller_stream;
namespace Tools {
void term(Caller_stream *, std::string prompt = ">");
void term(std::map<std::string, Caller_stream *>&, std::string prompt = ">");
void term(std::map<std::string, std::map<std::string,Caller_stream*>>& , std::string prompt = ">>>");
 } // namespace Tools
} // namespace CompoMe
