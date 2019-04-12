#pragma once

#include "Interfaces/I1/I1.hpp"

#include <vector>

class I1;
class I1_Dispatcher {

 private:
   std::vector<I1*> a_list_interface;

 public:
 void add_interface(I1*);
 void remove_interface(I1*);

 /////////////////////////////////////////////////////////////////////////////
 //                               FUNCTION                                  //
 /////////////////////////////////////////////////////////////////////////////
 virtual std::vector<int> add(int x,int y);

 /////////////////////////////////////////////////////////////////////////////
 //                               GET and SET                               //
 /////////////////////////////////////////////////////////////////////////////
 virtual std::vector<int>get_a() const;
 virtual void set_a(const int a);
};