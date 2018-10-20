
#include <iostream>

#include "Components/Empty/Empty.hpp"

namespace Empty{

  Empty::Empty()

  
                      {
                        std::cout << "--CONST : Empty" << std::endl;
                        return;
                      }


  //! Destructor
  Empty::~Empty() noexcept
                       {
                         std::cout << "--DEST  : Empty" << std::endl;
                         return;
                       }


  void Empty::configuration() {
    std::cout << "--CONF  : Empty" << std::endl;
    return;
  }

  void Empty::connection() {
    std::cout << "--CONECT: Empty" << std::endl;
    return;
  }

  void Empty::start() {
    std::cout << "--START : Empty" << std::endl;
    return;
  }


  void Empty::step() {
    std::cout << "--STEP  : Empty" << std::endl;
    return;
  }


  void Empty::stop() {
    std::cout << "--STOP  : Empty" << std::endl;
    return;
  }

  void Empty::status()
                   {
                     std::cout << "--STATUS: Empty" << std::endl;
                     return;
                   }

  

}