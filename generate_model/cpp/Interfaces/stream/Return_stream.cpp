#include <Interfaces/Return_stream.hpp>
#include <string>

Return_stream::Return_stream(std::istream *i_s, std::ostream *o_s)
    : si(i_s), so(o_s) {}

Return_stream::Return_stream(std::istream *p_s)
  : Return_stream(p_s, NULL){}

      Return_stream::Return_stream(std::ostream * p_s)
    : Return_stream(NULL, p_s) {}

Return_stream::~Return_stream() {}
char Return_stream::get() { return this->si->get(); }

Return_string_stream::Return_string_stream(Pull_f p_pull, End_f p_end)
    : Return_stream(&sf, &sf), pull_f(p_pull), end_f(p_end) {}

void Return_string_stream::pull() { this->pull_f(sf); }
void Return_string_stream::end() { this->end_f(sf); }

namespace std {
Return_stream &getline(Return_stream &is, string &str, char delim) {
  std::getline(*is.get_si(), str, delim);
  return is;
}

Return_stream &getline(Return_stream &is, string &str) {
  std::getline(*is.get_si(), str, '\n');
  return is;
}
} // namespace std
