#pragma once

#include <iostream>
#include <memory>
#include <ostream>

#include "Structs/Struct.hpp"

// TYPES

// STRUCTS

namespace DBus {
class MessageIterator;
class MessageAppendIterator;
} // namespace DBus

class Range : public CompoMe::Struct {
public:
  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////

  Range();

  virtual ~Range();

  Range(double p_min, double p_max);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  double get_min() const;
  void set_min(const double &);
  double &a_min();
  double get_max() const;
  void set_max(const double &);
  double &a_max();

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const Range &other) const;
  bool operator!=(const Range &other) const;

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
  double min;
  double max;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream &operator<<(std::ostream &os, const Range &c);
std::istream &operator>>(std::istream &os, Range &c);
///////////////////////////////////////////////////////////////////////////////
