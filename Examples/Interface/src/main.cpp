#include <sstream>

#include "Interfaces/Information/Information.hpp"
#include "Interfaces/Sensor/Sensor.hpp"
#include "term.hpp"

class Cpu_temp_inf : public Information {
public:
  Cpu_temp_inf() {}
  virtual ~Cpu_temp_inf() {}

  string get_name() override { return this->a_name; }
  string get_type() override { return "[TEMP]"; }
  string get_location() override { return this->a_loc; };

  // add function not accessible via parent interface.
  void set_name(string p_name) { this->a_name = p_name; }
  void set_location(string p_loc) { this->a_loc = p_loc; }

private:
  std::string a_name;
  std::string a_loc;
};

class Cpu_temp_sensor : public Sensor {
public:
  Cpu_temp_sensor() {
    this->temp_range.set_min(0);
    this->temp_range.set_max(100);
  }

  virtual ~Cpu_temp_sensor() {}

  double get_value() override { // in this example the result is just a constant
    return 35;
  }

  Range get_range() override { return temp_range; }

private:
  Range temp_range;
};

class Cpu_temp {
public:
  Cpu_temp() {}
  virtual ~Cpu_temp() {}
  Cpu_temp_inf info;
  Cpu_temp_sensor sensor;
};

int main(int argc, char *argv[]) {
  Cpu_temp t;
  t.info.set_name("MyComputer");
  t.info.set_location("Desk5");

  std::cout << "================ Term on Information Interface ================"
            << "\n";
  term(t.info.get_caller());

  std::cout << "================    Term on Sensor Interface   ================"
            << "\n";
  term(t.sensor.get_caller());

  return 0;
}
