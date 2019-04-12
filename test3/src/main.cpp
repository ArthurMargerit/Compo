#include "../inc/Data/Struct.hpp"
#include "../inc/Data/Struct_B_2.hpp"
#include "../inc/Interfaces/I1/I1_dispatcher.hpp"
#include "../inc/Components/C1/C1.hpp"
#include "../inc/Components/C4/C4.hpp"
#include "../inc/Data/Struct_B_2_1.hpp"
#include "../inc/Data/Struct_B_1.hpp"
#include "../inc/Data/Struct_B.hpp"
#include "../inc/Data/Struct_C.hpp"
#include "../inc/Data/Struct_Pair.hpp"

#include <iostream>
#include <sstream>

void p_te(B*a,B*b){
  std::cout << a << "\n";
  std::cout << b << "\n";
}


int itt (int b) {
  return ++b;
}

int main(int argc, char *argv[])
{

  // std::stringstream ss;

   Pair b2;
   B b;
   std::cout << b << "\n";
   std::cout << b2 << "\n";

   C1::C1 a;
   C4::C4 c;

   I1_Dispatcher i1d = c.get_d();
   i1d.add_interface(&a.a);
   i1d.add_interface(&a.a);
   i1d.add_interface(&a.a);
   i1d.add_interface(&a.a);

   std::vector<int> v = i1d.add(1,2);
   std::cout << "size: "<< v.size() << "\n";
   for (auto& vi : v) {
     std::cout << "> " << vi << "\n";
   }

  // ss<<&b2;

  // B *v=NULL;
  // ss>>v;
  // std::cout << v << "\n";
  // delete v;

  //  free(v);
  //  for (int i = 0; i < 10; ++i) {
  //    b2.get_vi().push_back(4);
  //    b2.get_vi().push_back(5);
  //    b2.get_vi().push_back(6);
  //    b2.get_vi().push_back(4);
  //    b2.get_vi().push_back(5);
  //    b2.get_vi().push_back(6);
  // }

  // b.get_vi().push_back(1);
  // b.get_vi().push_back(2);
  // b.get_vi().push_back(3);
  // b.set_a(999);
  // //  p_te(&b, &b2);
  // //  vector_i l_vi;

  // // std::cout << b.get_vi() << "\n";
  // // ss << b.get_vi() ;
  // // ss >> l_vi;
  // // std::cout <<  l_vi;

  // B bc;
  // std::cout << b << "\n";
  // ss << b;
  // ss >> bc;
  // std::cout << bc;

  // B_2_1 b21;
  // b21.get_t2();
  // b21.get_a();
  // b21.get_b();
  // std::cout << b21  << "\n";

  // B_1 b1;
  // b1.get_t();
  // b1.get_a();
  // b1.get_b();
  // std::cout << b1  << "\n";

  // B b;
  // b.get_a();
  // b.get_b();
  // std::cout << b  << "\n";

  // Pair p;
  // p.get_a();
  // p.get_b();
  // std::cout << p  << "\n";

  // C c;
  // c.get_a();
  // c.get_b();
  // c.get_c1();
  // c.get_c2();
  // c.get_c3();
  // c.get_d();
  // std::cout << c  << "\n";

  return 0;
}
