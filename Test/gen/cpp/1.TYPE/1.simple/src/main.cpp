#include "Data/code.hpp"
#include "catch.hpp"

TEST_CASE("Type Simple", "[Type][Simple]") {
  char c;
  uchar uc;

  short s;
  ushort us;

  long l;
  ulong ul;

  llong ll;
  ullong ull;

  int i;
  uint ui;

  i8 i1;
  i16 i2;
  i32 i3;
  i64 i4;

  ui8 ui1;
  ui16 ui2;
  ui32 ui3;
  ui64 ui4;

  float32 f1;
  float64 f2;

  CompoMe::String s1;
  CompoMe::String s2;
  CompoMe::String s3;

  pointer_of_int pc;
  pointer_of_pointer_of_int ppc;
  pointer_of_pointer_of_pointer_of_int pppc;

}
