#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/CompoMe_Log.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/CompoMe/Log/To_Stream_Log_I_log.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace CompoMe {

namespace Log {

class To_Stream : public CompoMe::Component {

public:
  // Contructor / Destructor
  To_Stream();
  virtual ~To_Stream() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////

  // PROVIDES

  To_Stream_Log_I_log &get_log();

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
  To_Stream_Log_I_log log;

public:
  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const To_Stream &c);
std::istream &operator>>(std::istream &is, To_Stream &c);

} // namespace Log

} // namespace CompoMe
