#include "Data/Struct_AAAAAA.hpp"
#include "Data/Struct_fac_AAAAAA.hpp"
#include "Data/Struct_fac_AAAAA.hpp"
#include "Data/Struct_fac_AAAA.hpp"
#include "Data/Struct_fac_AAA.hpp"
#include "Data/Struct_fac_AA.hpp"
#include "Data/Struct_fac_A.hpp"
#include "Data/Struct_fac.hpp"
#include <sstream>
#include "Data/code.hpp"

int main(int argc, char *argv[])
{
  init_code();

  std::shared_ptr<AAAAAA> pAAAAAA;
  std::shared_ptr<AAAAA> pAAAAA;
  std::shared_ptr<AAAA> pAAAA;
  std::shared_ptr<AAA> pAAA;
  std::shared_ptr<AA> pAA;
  std::shared_ptr<A> pA;
  std::shared_ptr<Struct> ps;

  AAAAAA a;
  std::stringstream ss;
  ss << &a;
  ss << &a;
  ss << &a;
  ss << &a;
  ss << &a;
  ss << &a;
  ss << &a;

  ss >> pAAAAAA;
  ss >> pAAAAA;
  ss >> pAAAA;
  ss >> pAAA;
  ss >> pAA;
  ss >> pA;
  ss >> ps;

  std::shared_ptr<Struct> ps1;
  std::shared_ptr<Struct> ps2;
  ss << "0";
  ss << "NULL";

  ss >> ps1;
  ss >> ps2;

  if(ps1 != nullptr){
    return 1;
  }

  if(ps2 != nullptr){
    return 2;
  }

  return 0;
}
