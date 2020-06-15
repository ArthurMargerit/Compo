#include "Data/File.hpp"
#include "Data/File_fac.hpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

File::File() : File(string()) {}

File::File(string p_path) : Struct(), path(p_path) {}

File::~File() {}

// GET SET ////////////////////////////////////////////////////////////////////
// get/set path
string File::get_path() const { return this->path; }

void File::set_path(const string &p_path) { this->path = p_path; }

string &File::a_path() { return this->path; }

// FUNCTION ///////////////////////////////////////////////////////////////////
// from File

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool File::operator==(const File &other) const {
  return true

         && this->path == other.path;
}

bool File::operator!=(const File &other) const { return !(*this == other); }
