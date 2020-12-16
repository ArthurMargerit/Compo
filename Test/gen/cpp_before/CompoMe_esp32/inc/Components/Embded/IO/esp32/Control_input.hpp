#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/CompoMe_esp32.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/Embded/IO/esp32/Control_input_Pin_in_control.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace Embded {

namespace IO {

namespace esp32 {

class Control_input : public CompoMe::Component {

public:
  // Contructor / Destructor
  Control_input();
  virtual ~Control_input() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////
  // pool_down
  bool get_pool_down() const;
  void set_pool_down(const bool &pool_down);
  // pool_up
  bool get_pool_up() const;
  void set_pool_up(const bool &pool_up);
  // pin_id
  ui8 get_pin_id() const;
  void set_pin_id(const ui8 &pin_id);

  // PROVIDES

  Control_input_Pin_in_control &get_control();

  // RECEIVERS

  // FUNCTIONS

  // SUB COMPONENTS

private:
  std::ostream &to_stream_data(std::ostream &,
                               CompoMe::Serialization_context_export &) const;
  std::ostream &to_stream_sc(std::ostream &,
                             CompoMe::Serialization_context_export &) const;
  std::ostream &
  to_stream_provide(std::ostream &,
                    CompoMe::Serialization_context_export &) const;

  std::istream &from_stream_data(std::istream &,
                                 CompoMe::Serialization_context_import &);
  std::istream &from_stream_sc(std::istream &,
                               CompoMe::Serialization_context_import &);
  std::istream &from_stream_provide(std::istream &,
                                    CompoMe::Serialization_context_import &);

public:
  std::ostream &
  to_stream(std::ostream &os,
            CompoMe::Serialization_context_export &p_ctx) const override;
  std::istream &
  from_stream(std::istream &is,
              CompoMe::Serialization_context_import &p_ctx) override;

  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  Control_input_Pin_in_control control;

  // RECEIVER

public:
  // REQUIRE MULTI

  // EMITTER
  // /////////////////////////////////////////////////////////////////////

  // DATA /////////////////////////////////////////////////////////////////////
  bool pool_down;
  bool pool_up;
  ui8 pin_id;

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const Control_input &c);
std::istream &operator>>(std::istream &is, Control_input &c);

} // namespace esp32

} // namespace IO

} // namespace Embded
