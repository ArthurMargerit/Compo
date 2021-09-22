#pragma once

#include "Components/Component.hpp"

#include "CompoMe/Log.hpp"
// TYPE
#include "Data/file.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/CompoMe/Log/Log_buffer_Log_I_log.hpp"

// require

#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

namespace CompoMe {

namespace Log {

class Log_buffer : public CompoMe::Component {

public:
  // Contructor / Destructor
  Log_buffer();
  virtual ~Log_buffer() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////
  // to_file
  bool get_to_file() const;
  void set_to_file(const bool &to_file);
  // file_path
  CompoMe::String get_file_path() const;
  void set_file_path(const CompoMe::String &file_path);

  // PROVIDES

  Log_buffer_Log_I_log &get_log();

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
  void to_stream(std::ostream &os,
                 CompoMe::Serialization_context_export &p_ctx) const override;
  void from_stream(std::istream &is,
                   CompoMe::Serialization_context_import &p_ctx) override;

  // INTERFACE ////////////////////////////////////////////////////////////////
  // PROVIDE
  Log_buffer_Log_I_log log;

  // RECEIVER

public:
  CompoMe::Require_helper_t<CompoMe::Log::Log_I> log_out;

  // REQUIRE MULTI

  // EMITTER
  // /////////////////////////////////////////////////////////////////////

  // DATA /////////////////////////////////////////////////////////////////////
  bool to_file;
  CompoMe::String file_path;

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

// std::ostream& operator<<(std::ostream& os, const CompoMe::Log::Log_buffer&
// c); std::istream& operator>>(std::istream& is, CompoMe::Log::Log_buffer& c);

} // namespace Log

} // namespace CompoMe
