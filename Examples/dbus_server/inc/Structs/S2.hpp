#pragma once

#include <iostream>
#include <memory>
#include <ostream>

#include "Structs/Struct.hpp"

// TYPES

#include "Types/i32.hpp"
// STRUCTS

namespace DBus {
class MessageIterator;
class MessageAppendIterator;
} // namespace DBus

class S2 : public CompoMe::Struct {
public:
  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////

  S2();

  virtual ~S2();

  S2(i32 p_i1, i32 p_i2);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  i32 get_i1() const;
  void set_i1(const i32 &);
  i32 &a_i1();
  i32 get_i2() const;
  void set_i2(const i32 &);
  i32 &a_i2();

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const S2 &other) const;
  bool operator!=(const S2 &other) const;

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
  i32 i2;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream &operator<<(std::ostream &os, const S2 &c);
std::istream &operator>>(std::istream &os, S2 &c);
///////////////////////////////////////////////////////////////////////////////
