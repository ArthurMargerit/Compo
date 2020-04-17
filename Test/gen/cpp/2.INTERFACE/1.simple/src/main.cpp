#include "catch.hpp"

#include "Interfaces/Empty/Empty.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IA/IA_fake.hpp"

#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IB/IB_fake.hpp"

#include "Interfaces/IC/IC.hpp"
#include "Interfaces/IC/IC_fake.hpp"

#include "Interfaces/ID/ID.hpp"
#include "Interfaces/ID/ID_fake.hpp"

#include "Interfaces/IE/IE.hpp"
#include "Interfaces/IE/IE_fake.hpp"


TEST_CASE("Interfaces simple", "[Interface][Simple0]") {

  // // Function_string_stream fs([](std::stringstream &ss) {
  // //   std::cout << ss.str() << "\n";
  // //   ss.str("");
  // // });

  // // Return_string_stream rs;

  // {
  //   IA *a = new IA_fake(fs, rs);
  //   a->get_a1();
  //   a->get_a2();
  //   a->get_a3();
  //   delete a;
  // }

  // {
  //   IB *b = new IB_fake(fs, rs);
  //   b->f1();
  //   b->f2(1);
  //   delete b;
  // }

  // std::string ask;
  // Function_string_stream fs1([&ask](std::stringstream &ss) {
  //   ask = ss.str();
  //   ss.str("");
  // });

  // Return_string_stream rs1([&ask](std::stringstream &ss){
  //   if(ask == "f1()") {
  //     So1 s;
  //     ss << s;
  //   }
  // });

  // {
  //   IE *b = new IE_fake(fs1, rs1);
  //   b->f1();
  //   b->f2(S1(1, 2, 3));
  //   b->f3(S1(1, 2, 3), S1(4, 5, 6));
  //   delete b;
  // }

}
