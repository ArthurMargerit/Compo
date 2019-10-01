#include "Errors/Math_exeption.hpp"
#include "Errors/Math_exeption_fac.hpp"
#include "Errors/Division_exeption.hpp"
#include "Data/code.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
  init_code();

  Math_exeption me;
  // Division_exeption de;
  // std::cout << me << std::endl;
  // std::cout << me.what() << std::endl << std::endl;

  // std::cout << de << std::endl;
  // std::cout << de.what() << std::endl;


  std::stringstream ss;
  ss << me;
  std::cout << me;
  Error *me2 = NULL;
  ss >> me2;

  return 0;

}
