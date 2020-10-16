#pragma once

#include "Components/Component.hpp"
#include "Types/CompoMe/String.hpp"

// TYPE
#include "Data/CompoMe_Tools.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/CompoMe/Config/DataProvider_AccessData_access.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace CompoMe {

namespace Config {

class DataProvider : public CompoMe::Component {

public:
  std::map<CompoMe::String,CompoMe::String> & a_values() {
    return values;
  }

  // Contructor / Destructor
  DataProvider();
  virtual ~DataProvider() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////

  // PROVIDES

  DataProvider_AccessData_access &get_access();

  // FUNCTIONS
  CompoMe::Config::Result_state set(CompoMe::String key, CompoMe::String val);

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
  DataProvider_AccessData_access access;

private:
  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////
  std::map< CompoMe::String , CompoMe::String > values;
  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const DataProvider &c);
std::istream &operator>>(std::istream &is, DataProvider &c);

} // namespace Config

} // namespace CompoMe
