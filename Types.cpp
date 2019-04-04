
#include "Data/Types.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const vector_i& vi)
{
  os << "[";
  if (vi.size() > 1)
    for (int i = 0; i < vi.size() - 1; i++) {
      os << vi[i] << ",";
    }

  if (vi.size() >= 1)
    os << vi[vi.size()-1];

    os << "]";
  return os;
}

std::istream &operator>>(std::istream &is, vector_i &vi) {
  vi = vector_i();
  {
    char c = is.get();
    if(c != '[') {
      std::cerr << c <<":Not a start array\n";
    }
  }

  bool first=true;

  while (true) {
    if (!first) {
      char c;
      c = is.get();
      if(c != ',') {
        if(c == ']')
          break;

        std::cerr << c << ":Not a sep and not end array\n";
      }

    } else {
      first = false;
    }

    int v=0;
    if(is >> v) {
      vi.push_back(v);
    } else {
      break;
    }
  }

  is.ignore(']');
  return is;
}
