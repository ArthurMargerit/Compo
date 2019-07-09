#include <Interfaces/Function_stream.hpp>
#include <string>

Function_stream::Function_stream(std::istream *p_is, std::ostream *p_os)
    : si(p_is), so(p_os) {}
Function_stream::Function_stream(std::istream *p_is)
    : Function_stream(p_is, NULL) {}
Function_stream::Function_stream(std::ostream *p_os)
    : Function_stream(NULL, p_os) {}

Function_stream::~Function_stream() {}

char Function_stream::get() { return this->si->get(); }

// FUNCTION_STREAM ////////////////////////////////////////////////////////////
Function_string_stream::Function_string_stream(Call_f p_call, Start_f p_start)
    : Function_stream(&sf, &sf), call_f(p_call), start_f(p_start) {}

void Function_string_stream::call() { this->call_f(sf); }
void Function_string_stream::start() { this->start_f(sf); }

namespace std {
Function_stream &getline(Function_stream &is, string &str, char delim) {
  std::getline(*is.get_si(), str, delim);
  return is;
}

Function_stream &getline(Function_stream &is, string &str) {
  std::getline(*is.get_si(), str, '\n');
  return is;
}
} // namespace std
