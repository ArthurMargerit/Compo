#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/CompoMe_Log.hpp"

// STRUCT

// INTERFACES
// provide

// require

#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace CompoMe {

namespace Log {

class Logger : public CompoMe::Component {

public:
  // Contructor / Destructor
  Logger();
  virtual ~Logger() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////
  // ignore
  CompoMe::Log::Kind_e get_ignore() const;
  void set_ignore(const CompoMe::Log::Kind_e &ignore);

  // PROVIDES

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

public:
  CompoMe::Require_helper_t<CompoMe::Log::Log_I> log_out;

  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////
  CompoMe::Log::Kind_e ignore;

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const Logger &c);
std::istream &operator>>(std::istream &is, Logger &c);

} // namespace Log

} // namespace CompoMe
