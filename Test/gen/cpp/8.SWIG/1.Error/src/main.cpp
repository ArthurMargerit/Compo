#include "Errors/s1.hpp"

void get_a_error(){
  s1 s = s1();
  throw s;
}

void get_a_error2(){
  s1 s = s1();
  throw &s;
}
