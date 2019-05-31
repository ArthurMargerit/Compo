#include <Components/Computer_temperature/Computer_temperature.hpp>

int main(int argc, char *argv[])
{

  Computer_temperature::Computer_temperature cp;
  cp.start();
  double v=0;
  while(v<36*1000) {
    cp.step();
    v = cp.cpu_temp.get().get_val();
    std::cout << v << "\n";
  }

  cp.stop();

  return 0;
}
