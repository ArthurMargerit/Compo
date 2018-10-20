
#include <iostream>

#include "Components/CA/CA.hpp"

namespace CA{

  CA::CA()

  
                      {
                        std::cout << "--CONST : CA" << std::endl;
                        return;
                      }


  //! Destructor
  CA::~CA() noexcept
                       {
                         std::cout << "--DEST  : CA" << std::endl;
                         return;
                       }


  void CA::configuration() {
    std::cout << "--CONF  : CA" << std::endl;
    return;
  }

  void CA::connection() {
    std::cout << "--CONECT: CA" << std::endl;
    return;
  }

  void CA::start() {
    std::cout << "--START : CA" << std::endl;
    return;
  }


  void CA::step() {
    std::cout << "--STEP  : CA" << std::endl;
    return;
  }


  void CA::stop() {
    std::cout << "--STOP  : CA" << std::endl;
    return;
  }

  void CA::status()
                   {
                     std::cout << "--STATUS: CA" << std::endl;
                     return;
                   }

  

}