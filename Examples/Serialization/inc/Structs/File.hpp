#pragma once

#include <iostream>
#include <memory>
#include <ostream>

#include "Structs/Struct.hpp"

// TYPES

#include "Types/CompoMe/String.hpp"
// STRUCTS

namespace DBus {
class MessageIterator;
class MessageAppendIterator;
} // namespace DBus

class File : public CompoMe::Struct {
public:
  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////

  File();

  virtual ~File();

  File(CompoMe::String p_path);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  CompoMe::String get_path() const;
  void set_path(const CompoMe::String &);
  CompoMe::String &a_path();

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const File &other) const;
  bool operator!=(const File &other) const;

  std::ostream &
  to_stream(std::ostream &os,
            CompoMe::Serialization_context_export &p_ctx) const override;
  std::istream &
  from_stream(std::istream &is,
              CompoMe::Serialization_context_import &p_ctx) override;

private:
  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  CompoMe::String path;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream &operator<<(std::ostream &os, const File &c);
std::istream &operator>>(std::istream &os, File &c);
///////////////////////////////////////////////////////////////////////////////
