
#include <iostream>

#include "Components/CE/CE.hpp"

namespace CE{

  CE::CE()

  
                      {
                        std::cout << "--CONST : CE" << std::endl;
                        return;
                      }


  //! Destructor
  CE::~CE() noexcept
                       {
                         std::cout << "--DEST  : CE" << std::endl;
                         return;
                       }


  void CE::configuration() {
    std::cout << "--CONF  : CE" << std::endl;
    return;
  }

  void CE::connection() {
    std::cout << "--CONECT: CE" << std::endl;
    return;
  }

  void CE::start() {
    std::cout << "--START : CE" << std::endl;
    return;
  }


  void CE::step() {
    std::cout << "--STEP  : CE" << std::endl;
    return;
  }


  void CE::stop() {
    std::cout << "--STOP  : CE" << std::endl;
    return;
  }

  void CE::status()
                   {
                     std::cout << "--STATUS: CE" << std::endl;
                     return;
                   }

  

}