#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES



#include "Interfaces/Math/Math.hpp"



namespace Calc {

  class Calc : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  

  // Facette
  
  Math* compute_serv;
  

  // c++ 11 def
  //! construction
  Calc();

  //! Copy constructor
  Calc(const Calc &other) = delete;

  //! Move constructor
  Calc(Calc &&other) = delete;

  //! Destructor
  virtual ~Calc() noexcept;

  //! Copy assignment operator
  Calc& operator=(const Calc &other) = delete;

  //! Move assignment operator
  Calc& operator=(Calc &&other) noexcept = delete;


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