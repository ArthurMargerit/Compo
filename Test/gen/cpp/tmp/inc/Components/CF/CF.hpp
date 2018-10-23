#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES

#include "Components/CF/CF_I1_p1.hpp"

#include "Components/CF/CF_I1_p2.hpp"

#include "Components/CF/CF_I1_p3.hpp"

#include "Components/CF/CF_I1_p4.hpp"



#include "Interfaces/I1/I1.hpp"

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/I1/I1.hpp"



namespace CF {

  class CF : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  
  I1_p1 p1;
  
  I1_p2 p2;
  
  I1_p3 p3;
  
  I1_p4 p4;
  

  // Facette
  
  I1* r1;
  
  I1* r2;
  
  I1* r3;
  
  I1* r4;
  

  // c++ 11 def
  //! construction
  CF();

  //! Copy constructor
  CF(const CF &other) = delete;

  //! Move constructor
  CF(CF &&other) = delete;

  //! Destructor
  virtual ~CF() noexcept;

  //! Copy assignment operator
  CF& operator=(const CF &other) = delete;

  //! Move assignment operator
  CF& operator=(CF &&other) noexcept = delete;


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