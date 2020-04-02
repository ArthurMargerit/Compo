#include "Components/C1/C1.hpp"

#include "connectors/Math_logger.hpp"
#include "connectors/Math_ext_logger.hpp"

#include "connectors/I_MA_logger.hpp"
#include "connectors/I_MA_logger2.hpp"

#include "connectors/A/I_MA_logger.hpp"
#include "connectors/B/I_MA_logger.hpp"

#include "connectors/B/A/I_MA_logger.hpp"
#include "connectors/A/B/I_MA_logger.hpp"


int main() {
  C1::C1 c;
  c.configuration();
  c.connection();
  c.start();

  std::ofstream ofs;
  ofs.open("c_math_p.sce");
  Math_logger a(ofs);
  a.r.set(&c.get_p());
  Math* i = &a.get_p();
  // function call
  i->ping(1, 2);
  i->ping(3, 2);
  i->ping(5, 2);

  // function
  i->f1(0);
  i->f2();
  i->f3();

  // get set call
  i->set_a(1);
  i->set_b(2);
  i->get_a();
  i->get_b();

  c.stop();
  ofs.close();

}
