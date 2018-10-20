
#include <iostream>

#include "Components/CG/CG.hpp"

namespace CG{

  CG::CG()

  
                      {
                        std::cout << "--CONST : CG" << std::endl;
                        return;
                      }


  //! Destructor
  CG::~CG() noexcept
                       {
                         std::cout << "--DEST  : CG" << std::endl;
                         return;
                       }


  void CG::configuration() {
    std::cout << "--CONF  : CG" << std::endl;
    return;
  }

  void CG::connection() {
    std::cout << "--CONECT: CG" << std::endl;
    return;
  }

  void CG::start() {
    std::cout << "--START : CG" << std::endl;
    return;
  }


  void CG::step() {
    std::cout << "--STEP  : CG" << std::endl;
    return;
  }


  void CG::stop() {
    std::cout << "--STOP  : CG" << std::endl;
    return;
  }

  void CG::status()
                   {
                     std::cout << "--STATUS: CG" << std::endl;
                     return;
                   }

  
  S1 CG::f1()
   {

   }
  

}