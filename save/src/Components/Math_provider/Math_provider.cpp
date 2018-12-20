
#include <iostream>

#include "Components/Math_provider/Math_provider.hpp"

namespace Math_provider{

  Math_provider::Math_provider():
  /* PROVIDE */
  m(this)
  {
    std::cout << "--CONST : Math_provider" << std::endl;
    return;
  }


  //! Destructor
  Math_provider::~Math_provider() noexcept
                       {
                         std::cout << "--DEST  : Math_provider" << std::endl;
                         return;
                       }


  void Math_provider::configuration() {
    std::cout << "--CONF  : Math_provider" << std::endl;
    return;
  }

  void Math_provider::connection() {
    std::cout << "--CONECT: Math_provider" << std::endl;
    return;
  }

  void Math_provider::start() {
    std::cout << "--START : Math_provider" << std::endl;
    return;
  }


  void Math_provider::step() {
    std::cout << "--STEP  : Math_provider" << std::endl;
    return;
  }


  void Math_provider::stop() {
    std::cout << "--STOP  : Math_provider" << std::endl;
    return;
  }

  void Math_provider::status()
                   {
                     std::cout << "--STATUS: Math_provider" << std::endl;
                     return;
                   }

  

}