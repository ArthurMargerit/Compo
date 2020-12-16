#include "Types/Embded/IO/Pin_State.hpp"

#include "Serialization_context.hpp"
#include <string>

namespace Embded {

namespace IO {} // namespace IO

} // namespace Embded

namespace std {
namespace {
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}
} // namespace

std::ostream &operator<<(std::ostream &os, const Embded::IO::Pin_State &c) {
  switch (c) {

  case Embded::IO::PIN_STATE_UNKNOWN:
    os << "Embded::IO::PIN_STATE_UNKNOWN";
    break;

  case Embded::IO::PIN_STATE_UP:
    os << "Embded::IO::PIN_STATE_UP";
    break;

  case Embded::IO::PIN_STATE_DOWN:
    os << "Embded::IO::PIN_STATE_DOWN";
    break;

  default:
    os << "ERROR";
  }

  return os;
}

std::istream &operator>>(std::istream &is, Embded::IO::Pin_State &c) {
  std::string str;
  str = CompoMe::get_word(is, {',', ')'}).first;

  switch (str2int(str.c_str())) {

  case str2int("-1"):                            // value
  case str2int("PIN_STATE_UNKNOWN"):             // no name space
  case str2int("Embded::IO::PIN_STATE_UNKNOWN"): // namespace
    c = Embded::IO::PIN_STATE_UNKNOWN;
    break;

  case str2int("1"):                        // value
  case str2int("PIN_STATE_UP"):             // no name space
  case str2int("Embded::IO::PIN_STATE_UP"): // namespace
    c = Embded::IO::PIN_STATE_UP;
    break;

  case str2int("0"):                          // value
  case str2int("PIN_STATE_DOWN"):             // no name space
  case str2int("Embded::IO::PIN_STATE_DOWN"): // namespace
    c = Embded::IO::PIN_STATE_DOWN;
    break;
  }
  return is;
}
} // namespace std
