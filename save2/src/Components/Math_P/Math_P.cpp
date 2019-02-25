
#include <iostream>

#include "Components/Math_P/Math_P.hpp"

namespace Math_P{

  Math_P::Math_P():
  /* PROVIDE */
  m(this)
  {
    std::cout << "--CONST : Math_P" << std::endl;
    return;
  }


  //! Destructor
  Math_P::~Math_P() noexcept
                       {
                         std::cout << "--DEST  : Math_P" << std::endl;
                         return;
                       }


  void Math_P::configuration() {
    std::cout << "--CONF  : Math_P" << std::endl;
    return;
  }

  void Math_P::connection() {
    std::cout << "--CONECT: Math_P" << std::endl;
    return;
  }

  void Math_P::start() {
    std::cout << "--START : Math_P" << std::endl;
    return;
  }


  void Math_P::step() {
    std::cout << "--STEP  : Math_P" << std::endl;
    return;
  }


  void Math_P::stop() {
    std::cout << "--STOP  : Math_P" << std::endl;
    return;
  }

  void Math_P::status()
                   {
                     std::cout << "--STATUS: Math_P" << std::endl;
                     return;
                   }

  

}