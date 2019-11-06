#include "Errors/Division_exeption.hpp"
#include "Errors/Exeption.hpp"
#include "Errors/Exeption_fac.hpp"
#include "Errors/Math_exeption.hpp"
#include "Errors/Math_exeption_fac.hpp"

#include "Data/code.hpp"
#include <iostream>
#include <memory>
#include <sstream>

int main(int argc, char *argv[]) {
  init_code();

  Math_exeption me;
  // Division_exeption de;
  // std::cout << me << std::endl;
  // std::cout << me.what() << std::endl << std::endl;

  // std::cout << de << std::endl;
  // std::cout << de.what() << std::endl;

  std::stringstream ss;
  ss << me;
  ss << &me;
  ss << &me;
  ss << &me;
  ss << &me;
  std::cout << &me;
  try {
  //  Error *me2 = NULL;
  std::shared_ptr<Error> pme2;
  std::shared_ptr<Exeption> pme3;
  std::shared_ptr<Math_exeption> pme4;

  Error *ppme2 = NULL;
  Math_exeption me2;

    ss >> me2;
    ss >> pme2;
    ss >> pme3;
    ss >> pme4;

    ss >> ppme2;
    std::cout << (pme2 != NULL) << std::endl;
    std::cout << (pme3 != NULL) << std::endl;
    std::cout << (pme4 != NULL) << std::endl;
    std::cout << (ppme2 != NULL) << std::endl;

    delete ppme2;

  } catch (char const *e) {
    std::cout << "err" << e << std::endl;
  }

  return 0;
}
