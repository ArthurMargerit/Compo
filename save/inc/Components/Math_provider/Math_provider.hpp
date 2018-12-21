#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES

#include "Components/Math_provider/Math_provider_Math_m.hpp"





namespace Math_provider {

  class Math_provider : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  
  Math_m m;
  

  // Facette
  

  // c++ 11 def
  //! construction
  Math_provider();

  //! Copy constructor
  Math_provider(const Math_provider &other) = delete;

  //! Move constructor
  Math_provider(Math_provider &&other) = delete;

  //! Destructor
  virtual ~Math_provider() noexcept;

  //! Copy assignment operator
  Math_provider& operator=(const Math_provider &other) = delete;

  //! Move assignment operator
  Math_provider& operator=(Math_provider &&other) noexcept = delete;


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
}