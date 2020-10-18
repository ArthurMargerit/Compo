#include "Types/CompoMe/String_d.hpp"

#include <sstream>
#include <string>

// TODO: escape wrong char

namespace CompoMe {

bool operator==(const CompoMe::String_d &a, const CompoMe::String_d &b) {
  return a.str == b.str;
}
  // \' 	single quote 	byte 0x27 in ASCII encoding
  // \" 	double quote 	byte 0x22 in ASCII encoding
  // \? 	question mark 	byte 0x3f in ASCII encoding
  // \\ 	backslash 	byte 0x5c in ASCII encoding
  // \a 	audible bell 	byte 0x07 in ASCII encoding
  // \b 	backspace 	byte 0x08 in ASCII encoding
  // \f 	form feed - new page 	byte 0x0c in ASCII encoding x
  // \n 	line feed - new line 	byte 0x0a in ASCII encoding x
  // \r 	carriage return 	byte 0x0d in ASCII encoding x
  // \t 	horizontal tab 	byte 0x09 in ASCII encoding x
  // \v 	vertical tab 	byte 0x0b in ASCII encoding x

  // \nnn 	arbitrary octal value 	byte nnn
  // \xnn 	arbitrary hexadecimal value 	byte nn
  // \unnnn (since C++11) 	universal character name

  // \Unnnnnnnn (since C++11) 	universal character name


std::ostream &operator<<(std::ostream &os, const CompoMe::String_d &c) {
  os << '"' ;
  for (char i_c : c.str){
    if(i_c == '"') {
      os << "\\\"";
        continue;
    }

    if(i_c == '\n') {
      os << "\\n";
      continue;
    }

    if(i_c == '\t') {
      os << "\\t";
      continue;
    }

    if(i_c == '\r') {
      os << "\\r";
      continue;
    }

    if(i_c == '\\') {
      os << "\\\\";
      continue;
    }

    if(i_c == '\a') {
      os << "\\a";
      continue;
    }

    if(i_c == '\b') {
      os << "\\b";
      continue;
    }

    if(i_c == '\f') {
      os << "\\f";
      continue;
    }

    if(i_c == '\v') {
      os << "\\v";
      continue;
    }

    if(i_c == '\?') {
      os << "\\?";
      continue;
    }

    os << i_c;
  }

  os << '"';
  return os;
}

std::istream &operator>>(std::istream &is, CompoMe::String_d &c) {
  if ('"' != is.peek()) {
    return is;
  }
  is.get();
  // remove "
  std::stringstream ss;
  while(true){

    char i_c = is.get();
    if(i_c == '"') {
      break;
    }

    if(i_c == '\\') {
      char i_c2 =  is.get();
      if(i_c2 == 'n'){
        ss << "\n";
        continue;
      }
      if(i_c2 == 'r'){
        ss << "\r";
        continue;
      }
      if(i_c2 == 'a'){
        ss << "\a";
        continue;
      }
      if(i_c2 == 'b'){
        ss << "\b";
        continue;
      }
      if(i_c2 == 't'){
        ss << "\t";
        continue;
      }
      if(i_c2 == 'v'){
        ss << "\v";
        continue;
      }
      if(i_c2 == '?'){
        ss << "\?";
        continue;
      }
      if(i_c2 == 'f'){
        ss << "\f";
        continue;
      }
      if(i_c2 == '\\'){
        ss << "\\";
        continue;
      }
      if(i_c2 == '"'){
        ss << "\"";
        continue;
      }
    }

    ss << i_c;
  }

  c.str = ss.str();
  return is;
}

bool operator<( const CompoMe::String_d &b, const CompoMe::String_d & a) {
  return a.str > b.str;
}

} // namespace CompoMe
