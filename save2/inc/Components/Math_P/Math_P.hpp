#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES

#include "Components/Math_P/Math_P_Math_m.hpp"





namespace Math_P {

  class Math_P : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  
  Math_m m;
  

  // Facette
  

  // c++ 11 def
  //! construction
  Math_P();

  //! Copy constructor
  Math_P(const Math_P &other) = delete;

  //! Move constructor
  Math_P(Math_P &&other) = delete;

  //! Destructor
  virtual ~Math_P() noexcept;

  //! Copy assignment operator
  Math_P& operator=(const Math_P &other) = delete;

  //! Move assignment operator
  Math_P& operator=(Math_P &&other) noexcept = delete;


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