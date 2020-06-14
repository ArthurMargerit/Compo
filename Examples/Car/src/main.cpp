#include "Components/Car/Gates/controller.hpp"

int main(int argc, char *argv[]) {
  Car::Gates::controller con;

  con.configuration();
  con.connection();
  con.start();
  for (int i = 0; i < 10;  ++i) {
    con.step();
  }

  con.stop();

  return 0;
}
