#include "Components/C1/C1.hpp"
#include "Components/C2/C2.hpp"
#include <iostream>


int main(int argc, char *argv[]) {
  C1::C1 c1;
  c1.save(std::cout);
  std::cout <<  "\n";

  C2::C2 c2;
  c2.save(std::cout);
  std::cout <<  "\n";
  return 0;
}
