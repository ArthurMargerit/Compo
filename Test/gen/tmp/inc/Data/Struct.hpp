#pragma once

#include <istream>
#include <ostream>
#include <utility>
#include <vector>

struct Struct {
  virtual void to_stream(std::ostream &) const = 0;
};

std::string get_type(std::istream &is);
std::pair<std::string, char> get_word(std::istream &is,
                                      std::vector<char> one_of);
std::istream &operator>>(std::istream &is, Struct *&c);
std::ostream &operator<<(std::ostream &os, const Struct *c);