
#include <iostream>

#include "Components/Calc/Calc.hpp"

namespace Calc{

  Calc::Calc():
  /* REQUIRE */
  compute_serv(NULL)
  {
    std::cout << "--CONST : Calc" << std::endl;
    return;
  }


  //! Destructor
  Calc::~Calc() noexcept
                       {
                         std::cout << "--DEST  : Calc" << std::endl;
                         return;
                       }


  void Calc::configuration() {
    std::cout << "--CONF  : Calc" << std::endl;
    return;
  }

  void Calc::connection() {
    std::cout << "--CONECT: Calc" << std::endl;
    return;
  }

  void Calc::start() {
    std::cout << "--START : Calc" << std::endl;
    return;
  }


  void Calc::step() {
    std::cout << "--STEP  : Calc" << std::endl;

    if(this->compute_serv != NULL)
      std::cout << this->compute_serv->add(1,2)  << "\n";

    return;
  }


  void Calc::stop() {
    std::cout << "--STOP  : Calc" << std::endl;
    return;
  }

  void Calc::status()
                   {
                     std::cout << "--STATUS: Calc" << std::endl;
                     return;
                   }
}
