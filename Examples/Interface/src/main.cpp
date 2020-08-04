#include <sstream>

#include "Interfaces/Information/Information.hpp"
#include "Interfaces/Sensor_v2/Sensor_v2.hpp"
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

class Cpu_temp_sensor : public Sensor_v2 {
private:
  double offset;
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

  virtual void add_offset(double offset) {
    this->temp_range.set_min(this->temp_range.get_min()+offset);
    this->temp_range.set_max(this->temp_range.get_max()+offset);
    this->offset = offset;
  }

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
  CompoMe::term(t.info.get_caller_stream());

  std::cout << "================    Term on Sensor Interface   ================"
            << "\n";

  // if you want to restrict the access to a parent level.
  Sensor_caller_stream cs(t.sensor);
  CompoMe::term(&cs);

  std::cout << "================    Term on Sensor v2 Interface   ================"
            << "\n";
  CompoMe::term(t.sensor.get_caller_stream());

  return 0;
}
