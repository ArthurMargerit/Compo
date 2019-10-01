#include "Errors/Error.hpp"

void Error::to_stream(std::ostream& os) const {
  //os << "{}";
  return;
}

std::string Error::what() {
  return std::string("-> Error\n");
}
