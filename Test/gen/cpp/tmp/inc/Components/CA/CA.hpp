#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES





namespace CA {

  class CA : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  

  // Facette
  

  // c++ 11 def
  //! construction
  CA();

  //! Copy constructor
  CA(const CA &other) = delete;

  //! Move constructor
  CA(CA &&other) = delete;

  //! Destructor
  virtual ~CA() noexcept;

  //! Copy assignment operator
  CA& operator=(const CA &other) = delete;

  //! Move assignment operator
  CA& operator=(CA &&other) noexcept = delete;


  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET
  

  int get_a() const {
    return a;
  }

  void set_a(const int a) {
    this->a = a;
  }
  


  // function
  

 private:

  
  int a;
  

 protected:

};
}