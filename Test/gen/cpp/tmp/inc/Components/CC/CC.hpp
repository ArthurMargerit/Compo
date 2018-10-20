#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES

#include "Components/CC/CC_I1_p1.hpp"



#include "Interfaces/I1/I1.hpp"



namespace CC {

  class CC : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  
  I1 p1;
  

  // Facette
  
  I1* r1;
  

  // c++ 11 def
  //! construction
  CC();

  //! Copy constructor
  CC(const CC &other) = delete;

  //! Move constructor
  CC(CC &&other) = delete;

  //! Destructor
  virtual ~CC() noexcept;

  //! Copy assignment operator
  CC& operator=(const CC &other) = delete;

  //! Move assignment operator
  CC& operator=(CC &&other) noexcept = delete;


  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET
  

  int get_b() const {
    return b;
  }

  void set_b(const int b) {
    this->b = b;
  }
  


  // function
  
  virtual int f1(int p1);
  

 private:

  
  int b;
  

 protected:

};
}