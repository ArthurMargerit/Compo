
#include <iostream>

#include "Components/CB/CB.hpp"

namespace CB{

  CB::CB()

  
                      {
                        std::cout << "--CONST : CB" << std::endl;
                        return;
                      }


  //! Destructor
  CB::~CB() noexcept
                       {
                         std::cout << "--DEST  : CB" << std::endl;
                         return;
                       }


  void CB::configuration() {
    std::cout << "--CONF  : CB" << std::endl;
    return;
  }

  void CB::connection() {
    std::cout << "--CONECT: CB" << std::endl;
    return;
  }

  void CB::start() {
    std::cout << "--START : CB" << std::endl;
    return;
  }


  void CB::step() {
    std::cout << "--STEP  : CB" << std::endl;
    return;
  }


  void CB::stop() {
    std::cout << "--STOP  : CB" << std::endl;
    return;
  }

  void CB::status()
                   {
                     std::cout << "--STATUS: CB" << std::endl;
                     return;
                   }

  
  int CB::f1(int p1)
   {

   }
  

}