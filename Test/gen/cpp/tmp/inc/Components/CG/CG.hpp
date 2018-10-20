#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT

#include "Data/Struct_S1.hpp"



// INTERFACES





namespace CG {

  class CG : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  

  // Facette
  

  // c++ 11 def
  //! construction
  CG();

  //! Copy constructor
  CG(const CG &other) = delete;

  //! Move constructor
  CG(CG &&other) = delete;

  //! Destructor
  virtual ~CG() noexcept;

  //! Copy assignment operator
  CG& operator=(const CG &other) = delete;

  //! Move assignment operator
  CG& operator=(CG &&other) noexcept = delete;


  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET
  


  // function
  
  virtual S1 f1();
  

 private:

  

 protected:

};
}