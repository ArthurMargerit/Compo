#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Serialization_context.hpp"

class Error : public Serializable_Item {
public:
  Error();
  virtual ~Error();

  virtual std::string what();
  virtual void real() = 0;
};

// std::pair<std::string, char> get_word(std::istream &is,
//                                       std::vector<char> one_of);

// std::istream &operator>>(std::istream &is, Error *&c);
// std::ostream &operator<<(std::ostream &os, const Error *c);
// std::istream &operator>>(std::istream &is, std::shared_ptr<Error> &c);
// std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Error> &c);

// void p_to_stream(std::ostream &os, const Error *p_c,
//                  Serialization_context_export &p_ctx);
// void p_to_stream(std::ostream &os, const std::shared_ptr<Error> c,
//                  Serialization_context_export &p_ctx);

// void p_from_stream(std::istream &is, std::shared_ptr<Error> &p_c,
//                    Serialization_context_import &p_ctx);
// void p_from_stream(std::istream &is, Error *&p_c,
//                    Serialization_context_import &p_ctx);