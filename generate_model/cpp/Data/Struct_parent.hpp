#pragma once

#include <ostream>
#include <istream>
#include <vector>
#include <utility>

struct Struct
{
  virtual ~Struct();
  virtual void to_stream(std::ostream& ) const =0;
  virtual std::string to_string() const = 0;
};

std::string get_type(std::istream &is);
std::pair<std::string,char> get_word(std::istream& is, std::vector<char> one_of);
std::istream &operator>>(std::istream &is, Struct *&c);
std::ostream& operator<<(std::ostream& os, const Struct* c);
