#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/CompoMe_esp32.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/Embded/IO/esp32/Control_output_Pin_out_control.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace Embded {

namespace IO {

namespace esp32 {

class Control_output : public CompoMe::Component {

public:
  // Contructor / Destructor
  Control_output();
  virtual ~Control_output() noexcept;

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

  Control_output_Pin_out_control &get_control();

  // RECEIVERS

  // FUNCTIONS
  void set(uint32_t);
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
  Control_output_Pin_out_control control;

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

std::ostream &operator<<(std::ostream &os, const Control_output &c);
std::istream &operator>>(std::istream &is, Control_output &c);

} // namespace esp32

} // namespace IO

} // namespace Embded
