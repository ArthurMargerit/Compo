#pragma once

#include <ostream>

#include "Data/Types.hpp"


#include "Data/Struct.hpp"









#include "Data/Struct_A.hpp"












#include "Data/Struct_B.hpp"




struct C : public Struct {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  int a;
  int b;
  A c;
  A c1;
  A c2;
  A c3;
  B d;

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  C();

  

  C(int p_a,int p_b,A p_c,A p_c1,A p_c2,A p_c3,B p_d);
  

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  int get_a() const;

  void set_a(const int value);
  int get_b() const;

  void set_b(const int value);
  A get_c() const;

  void set_c(const A value);
  A get_c1() const;

  void set_c1(const A value);
  A get_c2() const;

  void set_c2(const A value);
  A get_c3() const;

  void set_c3(const A value);
  B get_d() const;

  void set_d(const B value);


  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

virtual void to_stream(std::ostream&) const;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const C& c);
std::istream& operator>>(std::istream& os,C& c);

std::ostream& operator<<(std::ostream& os, const C* c);
std::istream& operator>>(std::istream& os,C*& c);
