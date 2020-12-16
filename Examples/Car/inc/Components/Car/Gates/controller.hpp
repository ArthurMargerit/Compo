#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/file.hpp"

// STRUCT

// INTERFACES
// provide

#include "Components/Car/Gates/controller_Window_win.hpp"

#include "Components/Car/Gates/controller_Locker_locker.hpp"

// require

#include "Interfaces/Car/Reporter/Reporter.hpp"

// require multi

// SUB COMPONENT  ////////////////////////////////////////////////////////////

// SUB CONNECTOR ////////////////////////////////////////////////////////////

#include <iostream>

namespace Car {

namespace Gates {

class controller : public CompoMe::Component {

public:
  // Contructor / Destructor
  controller();
  virtual ~controller() noexcept;

  // composant initialisation
  void configuration() override;
  void connection() override;
  void start() override;
  void stop() override;
  void step() override;
  void status() override;

  // GET/SET //////////////////////////////////////////////////////////////////

  // PROVIDES

  controller_Window_win &get_win();

  controller_Locker_locker &get_locker();

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
  controller_Window_win win;
  controller_Locker_locker locker;

public:
  CompoMe::Require_helper_t<Car::Reporter> reporting_station;

  // REQUIRE MULTI

  // DATA /////////////////////////////////////////////////////////////////////

  // SUB COMPONENT ////////////////////////////////////////////////////////////

  // SUB CONNECTOR ////////////////////////////////////////////////////////////
};

std::ostream &operator<<(std::ostream &os, const controller &c);
std::istream &operator>>(std::istream &is, controller &c);

} // namespace Gates

} // namespace Car
