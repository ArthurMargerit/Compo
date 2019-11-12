#include <Data/Struct_A.hpp>
#include <Data/Struct_B.hpp>
#include <Data/Struct_C.hpp>

int main(int argc, char *argv[]) {
  A a1;
  A a2(1,2,3);
  //  A a3(1);

  if (!(a1.get_aa() == -10 && a1.get_ab() == -10 && a1.get_ac() == 10)) {
    std::cerr << "Error: 1";
    return -1;
  }

  if (!(a2.get_aa() == 1 && a2.get_ab() == 2 && a2.get_ac() == 3)) {
    std::cerr << "Error: 2";
    return -1;
  }

  // if (!(a3.get_aa() == 1 && a3.get_ab() == -10 && a3.get_ac() == 10)) {
  //   return -1;
  // }

  return 0;
}
