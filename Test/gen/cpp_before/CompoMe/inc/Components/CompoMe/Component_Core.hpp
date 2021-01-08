#pragma once

#include "Components/Component.hpp"

#include "CompoMe/Log.hpp"
// TYPE
#include "Data/CompoMe.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/CompoMe/Component_Core_Component_Control_handle.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

namespace CompoMe {

class Component_Core : public CompoMe::Component {

public:
  // Contructor / Destructor
  Component_Core();
  virtual ~Component_Core() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////
  // name
  CompoMe::String get_name() const;
  void set_name(const CompoMe::String &name);
  // state
  CompoMe::Component_state get_state() const;
  void set_state(const CompoMe::Component_state &state);

  // PROVIDES

  Component_Core_Component_Control_handle &get_handle();

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
  Component_Core_Component_Control_handle handle;

  // RECEIVER

public:
  // REQUIRE MULTI

  // EMITTER
  // /////////////////////////////////////////////////////////////////////

  // DATA /////////////////////////////////////////////////////////////////////
  CompoMe::String name;
  CompoMe::Component_state state;

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const Component_Core &c);
std::istream &operator>>(std::istream &is, Component_Core &c);

} // namespace CompoMe
