#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/file.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/Sensor_Information_I_information.hpp"

#include "Components/Sensor_Thermal_Sensor_I_capteur1.hpp"

// require

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

class Sensor : public CompoMe::Component {

public:
  // Contructor / Destructor
  Sensor();
  virtual ~Sensor() noexcept;

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
  // type
  CompoMe::String get_type() const;
  void set_type(const CompoMe::String &type);
  // location
  CompoMe::String get_location() const;
  void set_location(const CompoMe::String &location);

  // PROVIDES

  Sensor_Information_I_information &get_information();

  Sensor_Thermal_Sensor_I_capteur1 &get_capteur1();

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
  Sensor_Information_I_information information;
  Sensor_Thermal_Sensor_I_capteur1 capteur1;

public:
  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////
  CompoMe::String name;
  CompoMe::String type;
  CompoMe::String location;

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const Sensor &c);
std::istream &operator>>(std::istream &is, Sensor &c);
