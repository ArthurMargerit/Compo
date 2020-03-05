#pragma once

#include "Serialization_context.hpp"
#include <istream>
#include <ostream>
#include <utility>
#include <memory>
#include <vector>

struct Struct {
  virtual ~Struct();
  virtual std::ostream &to_stream(std::ostream &,
                                  Serialization_context &) const = 0;
  virtual std::istream &from_stream(std::istream &is,
                                    Serialization_context &p_ctx) = 0;
  virtual std::string to_string() const = 0;
};

std::pair<std::string, char> get_word(std::istream &is,
                                      std::vector<char> one_of);

std::istream &operator>>(std::istream &is, Struct *&c);
std::ostream &operator<<(std::ostream &os, const Struct *&c);
std::istream &operator>>(std::istream &is, std::shared_ptr<Struct> &c);
std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Struct> &c);

void p_to_stream(std::ostream &os, const Struct *p_c, Serialization_context &p_ctx);
void p_from_stream(std::istream &is, Struct *&p_c, Serialization_context &p_ctx);
