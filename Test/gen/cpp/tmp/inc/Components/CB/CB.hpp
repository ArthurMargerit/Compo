#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES





namespace CB {

  class CB : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  

  // Facette
  

  // c++ 11 def
  //! construction
  CB();

  //! Copy constructor
  CB(const CB &other) = delete;

  //! Move constructor
  CB(CB &&other) = delete;

  //! Destructor
  virtual ~CB() noexcept;

  //! Copy assignment operator
  CB& operator=(const CB &other) = delete;

  //! Move assignment operator
  CB& operator=(CB &&other) noexcept = delete;


  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET
  


  // function
  
  virtual int f1(int p1);
  

 private:

  

 protected:

};
}