#include "Data/Struct_A.hpp"
#include "Data/Struct_B.hpp"
#include "Data/Struct_C.hpp"

#include "Data/Type_pC.hpp"
#include "Data/Type_pA.hpp"


#include <memory>
#include <sstream>

int main(int argc, char *argv[]) {
  C c;
  A a;
  pC pc = nullptr;
  pA pa = nullptr;
  if(pc != NULL){throw "wrong";}
  if(pa != NULL){throw "wrong";}

  pc = &c;
  pa = &a;

  if(pc == NULL){throw "wrong";}
  if(pa == NULL){throw "wrong";}

  return 0;
}
