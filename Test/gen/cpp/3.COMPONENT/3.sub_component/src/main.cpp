#include <iostream>

#include "Components/Empty/Empty.hpp"
#include "Components/S_C1/S_C1.hpp"
#include "Components/S_C2/S_C2.hpp"

int main(int argc, char *argv[]) {

  std::cout << "\n->->  Empty  <-<-\n";
  {
    Empty::Empty c0;

    c0.configuration();

    c0.connection();

    c0.start();

    c0.step();
    c0.step();
    c0.step();

    c0.stop();
  }

  std::cout << "\n->->  S_C1  <-<-\n";
  {
    S_C1::S_C1 c1;
    c1.configuration();

    c1.connection();

    c1.start();

    c1.step();
    c1.step();
    c1.step();

    c1.stop();
  }

  std::cout << "\n->->  S_C2  <-<-\n";
  {
    S_C2::S_C2 c2;

    c2.configuration();

    c2.connection();

    c2.start();

    c2.step();
    c2.step();
    c2.step();

    c2.stop();
  }

  return 0;
}
