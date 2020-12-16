#pragma once

#include "Events/Event.hpp"

// TYPES

#include "Types/ui8.hpp"

#include "Types/Embded/IO/Pin_State.hpp"
// STRUCTS

namespace DBus {
class MessageIterator;
class MessageAppendIterator;
} // namespace DBus

namespace Embded {

namespace IO {

class Pin_change : public CompoMe::Event {
public:
  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////

  Pin_change();

  virtual ~Pin_change();

  Pin_change(ui8 p_pin_id, Embded::IO::Pin_State p_pin_value);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  ui8 get_pin_id() const;
  void set_pin_id(const ui8 &);
  ui8 &a_pin_id();
  Embded::IO::Pin_State get_pin_value() const;
  void set_pin_value(const Embded::IO::Pin_State &);
  Embded::IO::Pin_State &a_pin_value();

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const Embded::IO::Pin_change &other) const;
  bool operator!=(const Embded::IO::Pin_change &other) const;

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
  ui8 pin_id;
  Embded::IO::Pin_State pin_value;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream &operator<<(std::ostream &os, const Pin_change &c);
std::istream &operator>>(std::istream &os, Pin_change &c);
///////////////////////////////////////////////////////////////////////////////

} // namespace IO

} // namespace Embded
