#pragma once

#include <istream>
#include <ostream>

namespace Embded {

namespace IO {

enum Pin_State {

  PIN_STATE_UNKNOWN = -1,

  PIN_STATE_UP = 1,

  PIN_STATE_DOWN = 0

};

} // namespace IO

} // namespace Embded

namespace std {

std::ostream &operator<<(std::ostream &os, const Embded::IO::Pin_State &);

std::istream &operator>>(std::istream &is, Embded::IO::Pin_State &);
} // namespace std
