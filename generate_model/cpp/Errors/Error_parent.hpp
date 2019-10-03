#pragma once

#include <string>
#include <vector>
#include <memory>

struct Error {
public:
  virtual void to_stream(std::ostream& ) const =0;
  virtual std::string what();
  virtual void real()=0;
};

std::string get_type(std::istream &is);
std::pair<std::string,char> get_word(std::istream& is, std::vector<char> one_of);
std::istream &operator>>(std::istream &is, Error *&c);
std::ostream& operator<<(std::ostream& os, const Error *c);
std::istream &operator>>(std::istream &is, std::shared_ptr<Error> &c);
