#pragma once
#include <fstream>

#include "Components/Component.hpp"

// TYPE
#include "Data/CompoMe_Log.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/CompoMe/Log/To_File_Log_I_log.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace CompoMe {

namespace Log {

class To_File : public CompoMe::Component {

public:
  // Contructor / Destructor
  To_File();
  virtual ~To_File() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  To_File& operator=(const To_File&t){

    return *this;}

  // GET/SET //////////////////////////////////////////////////////////////////
  // path
  CompoMe::String get_path() const;
  void set_path(const CompoMe::String &path);

  // PROVIDES

  To_File_Log_I_log &get_log();

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
  To_File_Log_I_log log;

public:
  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////
  CompoMe::String path;

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
private:
  std::ofstream output;

public:
  std::ostream &get_output() { return this->output; }
};

std::ostream &operator<<(std::ostream &os, const To_File &c);
std::istream &operator>>(std::istream &is, To_File &c);

} // namespace Log

} // namespace CompoMe
