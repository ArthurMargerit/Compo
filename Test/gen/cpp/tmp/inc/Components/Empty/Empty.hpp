#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES





namespace Empty {

  class Empty : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  

  // Facette
  

  // c++ 11 def
  //! construction
  Empty();

  //! Copy constructor
  Empty(const Empty &other) = delete;

  //! Move constructor
  Empty(Empty &&other) = delete;

  //! Destructor
  virtual ~Empty() noexcept;

  //! Copy assignment operator
  Empty& operator=(const Empty &other) = delete;

  //! Move assignment operator
  Empty& operator=(Empty &&other) noexcept = delete;


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