#include "Errors/Math_exeption.hpp"
#include "Errors/Division_exeption.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  Math_exeption me;
  Division_exeption de;
  std::cout << me << std::endl;
  std::cout << me.what() << std::endl << std::endl;

  std::cout << de << std::endl;
  std::cout << de.what() << std::endl;

  return 0;
}
