#include "Types/CompoMe/Json.hpp"
#include "Interfaces/Function_stream_recv.hpp"

namespace CompoMe {

// function to allow int and double parsing
CompoMe::Function_stream_recv &operator>>(CompoMe::Function_stream_recv &s,
                                          nlohmann::json &e) {
  char r = s.get_si().peek();
  if (r == '[' || r == 'f' || r == 't' || r == '{' || r == '"' || r == '\'') {
    s.get_si() >> e;
  } else {
    double a;
    s.get_si() >> a;
    e = a;
  }
  return s;
}
} // namespace CompoMe
