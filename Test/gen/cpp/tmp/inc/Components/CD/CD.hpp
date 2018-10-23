#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES

#include "Components/CD/CD_I1_p1.hpp"

#include "Components/CD/CD_I1_p2.hpp"

#include "Components/CD/CD_I1_p3.hpp"

#include "Components/CD/CD_I1_p4.hpp"





namespace CD {

  class CD : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  
  I1_p1 p1;
  
  I1_p2 p2;
  
  I1_p3 p3;
  
  I1_p4 p4;
  

  // Facette
  

  // c++ 11 def
  //! construction
  CD();

  //! Copy constructor
  CD(const CD &other) = delete;

  //! Move constructor
  CD(CD &&other) = delete;

  //! Destructor
  virtual ~CD() noexcept;

  //! Copy assignment operator
  CD& operator=(const CD &other) = delete;

  //! Move assignment operator
  CD& operator=(CD &&other) noexcept = delete;


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