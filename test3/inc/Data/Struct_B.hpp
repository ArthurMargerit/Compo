#pragma once

#include <ostream>

#include "Data/Types.hpp"


#include "Data/Struct.hpp"









#include "Data/Struct_A.hpp"




struct B : public Struct {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  int a;
  int b;
  A c;

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  B();

  

  B(int p_a,int p_b,A p_c);
  

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  int get_a() const;

  void set_a(const int value);
  int get_b() const;

  void set_b(const int value);
  A get_c() const;

  void set_c(const A value);


  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////
virtual void action1();
virtual void action2(int a);
virtual int action3();
virtual int action4(int a);
virtual int action5(int a,int b);

virtual void to_stream(std::ostream&) const;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const B& c);
std::istream& operator>>(std::istream& os,B& c);

std::ostream& operator<<(std::ostream& os, const B* c);
std::istream& operator>>(std::istream& os,B*& c);
