#include "Interfaces/Function_stream_recv.hpp"

Function_stream_recv &getline(Function_stream_recv &is, std::string &str,
                              char delim) {
  std::getline(is.get_si(), str, delim);
  return is;
}
Function_stream_recv &getline(Function_stream_recv &is, std::string &str) {
  std::getline(is.get_si(), str, '\n');
  return is;
}
