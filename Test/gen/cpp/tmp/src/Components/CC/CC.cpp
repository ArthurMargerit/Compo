
#include <iostream>

#include "Components/CC/CC.hpp"

namespace CC{

  CC::CC()

  
  :
  p1(this)
  
                      {
                        std::cout << "--CONST : CC" << std::endl;
                        return;
                      }


  //! Destructor
  CC::~CC() noexcept
                       {
                         std::cout << "--DEST  : CC" << std::endl;
                         return;
                       }


  void CC::configuration() {
    std::cout << "--CONF  : CC" << std::endl;
    return;
  }

  void CC::connection() {
    std::cout << "--CONECT: CC" << std::endl;
    return;
  }

  void CC::start() {
    std::cout << "--START : CC" << std::endl;
    return;
  }


  void CC::step() {
    std::cout << "--STEP  : CC" << std::endl;
    return;
  }


  void CC::stop() {
    std::cout << "--STOP  : CC" << std::endl;
    return;
  }

  void CC::status()
                   {
                     std::cout << "--STATUS: CC" << std::endl;
                     return;
                   }

  
  int CC::f1(int p1)
   {

   }
  

}