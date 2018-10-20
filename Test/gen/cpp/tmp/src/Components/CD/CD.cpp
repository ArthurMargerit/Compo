
#include <iostream>

#include "Components/CD/CD.hpp"

namespace CD{

  CD::CD()

  
  :
  p1(this),
  
  
  p2(this),
  
  
  p3(this),
  
  
  p4(this)
  
                      {
                        std::cout << "--CONST : CD" << std::endl;
                        return;
                      }


  //! Destructor
  CD::~CD() noexcept
                       {
                         std::cout << "--DEST  : CD" << std::endl;
                         return;
                       }


  void CD::configuration() {
    std::cout << "--CONF  : CD" << std::endl;
    return;
  }

  void CD::connection() {
    std::cout << "--CONECT: CD" << std::endl;
    return;
  }

  void CD::start() {
    std::cout << "--START : CD" << std::endl;
    return;
  }


  void CD::step() {
    std::cout << "--STEP  : CD" << std::endl;
    return;
  }


  void CD::stop() {
    std::cout << "--STOP  : CD" << std::endl;
    return;
  }

  void CD::status()
                   {
                     std::cout << "--STATUS: CD" << std::endl;
                     return;
                   }

  

}