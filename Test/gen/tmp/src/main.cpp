
#include "Data/Struct_A.hpp"
#include "Data/Struct_AA.hpp"
#include "Data/Types.hpp"
#include <vector>

#include <iostream>


int main(int argc, char *argv[]) {
  vector_of_A va;
  std::vector<Struct *> vs;

  A a1;
  AA a2;
  AAA a3;
  AAAA a4;
  AAAAA a5;
  AAAAAA a6;

  va.push_back(&a1);
  va.push_back(&a2);
  va.push_back(&a3);
  va.push_back(&a4);
  va.push_back(&a5);
  va.push_back(&a6);

  vs.push_back(&a1);
  vs.push_back(&a2);
  vs.push_back(&a3);
  vs.push_back(&a4);
  vs.push_back(&a5);
  vs.push_back(&a6);
  
  for (auto l : va ) {
    l->get_a();
  }

  return 0;
}
