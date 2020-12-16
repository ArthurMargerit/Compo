#include "Structs/File.hpp"
#include "Structs/File_fac.hpp"

#include <istream>
#include <ostream>
#include <sstream>

File::File() : File(CompoMe::String()) {}

File::File(CompoMe::String p_path) : Struct(), path(p_path) {}

File::~File() {}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool File::operator==(const File &other) const {
  return true

         && this->path == other.path;
}

bool File::operator!=(const File &other) const { return !(*this == other); }
