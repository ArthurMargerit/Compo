#pragma once

#include "Components/Component.hpp"

#include "CompoMe/Log.hpp"
// TYPE
#include "Data/CompoMe_Log.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/CompoMe/Log/Filter_Log_I_input_log.hpp"

#include "Components/CompoMe/Log/Filter_Filter_Management_I_filter_Manager.hpp"

// require

#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"

#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

namespace CompoMe {

namespace Log {

class Filter : public CompoMe::Component {

public:
  // Contructor / Destructor
  Filter();
  virtual ~Filter() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////
  // filter
  CompoMe::Log::Kind_e get_filter() const;
  void set_filter(const CompoMe::Log::Kind_e &filter);

  // PROVIDES

  Filter_Log_I_input_log &get_input_log();

  Filter_Filter_Management_I_filter_Manager &get_filter_Manager();

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
  Filter_Log_I_input_log input_log;
  Filter_Filter_Management_I_filter_Manager filter_Manager;

  // RECEIVER

public:
  CompoMe::Require_helper_t<CompoMe::Log::Log_I> pass_log;

  CompoMe::Require_helper_t<CompoMe::Log::Log_I> refused_log;

  // REQUIRE MULTI

  // EMITTER
  // /////////////////////////////////////////////////////////////////////

  // DATA /////////////////////////////////////////////////////////////////////
  CompoMe::Log::Kind_e filter;

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const Filter &c);
std::istream &operator>>(std::istream &is, Filter &c);

} // namespace Log

} // namespace CompoMe
