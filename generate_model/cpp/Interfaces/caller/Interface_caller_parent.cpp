#include "Interfaces/Caller.hpp"

Caller::Caller() {
  
}

Caller::~Caller() {
  
}

namespace std {
  Function_stream &getline(Function_stream &is, string &str, char delim) {
    std::getline(*is.si, str, delim);
    return is;
  }

  Function_stream &getline(Function_stream &is, string &str) {
    std::getline(*is.si, str, '\n');
    return is;
  }

  Return_stream &getline(Return_stream &is, string &str, char delim) {
    std::getline(*is.si, str, delim);
    return is;
  }

  Return_stream &getline(Return_stream &is, string &str) {
    std::getline(*is.si, str, '\n');
    return is;
  }
} // namespace std
