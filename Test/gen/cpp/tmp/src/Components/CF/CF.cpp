
#include <iostream>

#include "Components/CF/CF.hpp"

namespace CF{

  CF::CF()

  
  :
  p1(this),
  
  
  p2(this),
  
  
  p3(this),
  
  
  p4(this)
  
                      {
                        std::cout << "--CONST : CF" << std::endl;
                        return;
                      }


  //! Destructor
  CF::~CF() noexcept
                       {
                         std::cout << "--DEST  : CF" << std::endl;
                         return;
                       }


  void CF::configuration() {
    std::cout << "--CONF  : CF" << std::endl;
    return;
  }

  void CF::connection() {
    std::cout << "--CONECT: CF" << std::endl;
    return;
  }

  void CF::start() {
    std::cout << "--START : CF" << std::endl;
    return;
  }


  void CF::step() {
    std::cout << "--STEP  : CF" << std::endl;
    return;
  }


  void CF::stop() {
    std::cout << "--STOP  : CF" << std::endl;
    return;
  }

  void CF::status()
                   {
                     std::cout << "--STATUS: CF" << std::endl;
                     return;
                   }

  

}