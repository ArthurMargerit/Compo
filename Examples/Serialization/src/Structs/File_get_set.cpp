#include "Structs/File.hpp"

// GET SET ////////////////////////////////////////////////////////////////////

// get/set path
CompoMe::String File::get_path() const { return this->path; }

void File::set_path(const CompoMe::String &p_path) { this->path = p_path; }

CompoMe::String &File::a_path() { return this->path; }
