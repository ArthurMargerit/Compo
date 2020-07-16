#pragma once

#include <iostream>
#include <memory>
#include <ostream>

#include "Structs/Struct.hpp"

#include "Types/i32.hpp"

namespace DBus {
class MessageIterator;
class MessageAppendIterator;
} // namespace DBus

class S1 : public CompoMe::Struct {
public:
  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////

  S1();

  virtual ~S1();

  S1(i32 p_i1);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  i32 get_i1() const;
  void set_i1(const i32 &);
  i32 &a_i1();

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const S1 &other) const;
  bool operator!=(const S1 &other) const;

  std::ostream &
  to_stream(std::ostream &os,
            CompoMe::Serialization_context_export &p_ctx) const override;
  std::istream &
  from_stream(std::istream &is,
              CompoMe::Serialization_context_import &p_ctx) override;

  DBus::MessageAppendIterator &
  to_stream(DBus::MessageAppendIterator &,
            CompoMe::Serialization_context_export &) const override;
  DBus::MessageIterator &
  from_stream(DBus::MessageIterator &,
              CompoMe::Serialization_context_import &) override;

private:
  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  i32 i1;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream &operator<<(std::ostream &os, const S1 &c);
std::istream &operator>>(std::istream &os, S1 &c);
///////////////////////////////////////////////////////////////////////////////
