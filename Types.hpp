#pragma once

#include <string>
#include <vector>


typedef std::string mstring;
typedef std::vector<int> vector_i;
std::ostream& operator<<(std::ostream& os, const vector_i& vi);
std::istream& operator>>(std::istream& os, vector_i& vi);
