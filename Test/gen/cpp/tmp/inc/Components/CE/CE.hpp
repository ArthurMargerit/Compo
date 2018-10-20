#pragma once

// PARENT
#include "Components/Component.hpp"


// TYPE
#include "Data/Types.hpp"

// STRUCT



// INTERFACES



#include "Interfaces/I1/I1.hpp"

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/I1/I1.hpp"



namespace CE {

  class CE : public Component
{
 public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle
  

  // Facette
  
  I1* r1;
  
  I1* r2;
  
  I1* r3;
  
  I1* r4;
  

  // c++ 11 def
  //! construction
  CE();

  //! Copy constructor
  CE(const CE &other) = delete;

  //! Move constructor
  CE(CE &&other) = delete;

  //! Destructor
  virtual ~CE() noexcept;

  //! Copy assignment operator
  CE& operator=(const CE &other) = delete;

  //! Move assignment operator
  CE& operator=(CE &&other) noexcept = delete;


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