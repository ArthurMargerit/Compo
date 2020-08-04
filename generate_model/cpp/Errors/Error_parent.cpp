#include "Errors/Error.hpp"
#include "Serialization_context.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include <sstream>

namespace CompoMe {

Error::Error() {
  bs += what_s();
}
Error::~Error() {}

std::string Error::what_s() const { return std::string("-> Error\n"); }

} // namespace CompoMe
