#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

#include "Components/Simple_Compo/Simple_Compo_Hello_Interface_interface.hpp"

namespace Simple_Compo {

class Simple_Compo : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  Hello_Interface_interface interface;

  // Facette

  // c++ 11 def
  //! construction
  Simple_Compo();

  //! Copy constructor
  Simple_Compo(const Simple_Compo &other) = delete;

  //! Move constructor
  Simple_Compo(Simple_Compo &&other) = delete;

  //! Destructor
  virtual ~Simple_Compo() noexcept;

  //! Copy assignment operator
  Simple_Compo &operator=(const Simple_Compo &other) = delete;

  //! Move assignment operator
  Simple_Compo &operator=(Simple_Compo &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  // function

private:
protected:
};
} // namespace Simple_Compo