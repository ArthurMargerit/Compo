#include "Interfaces/I1/I1_dispatcher.hpp"

void I1_Dispatcher::add_interface(I1* p_i) {
  this->a_list_interface.push_back(p_i);
}

void I1_Dispatcher::remove_interface(I1*) {

}
 std::vector<int> I1_Dispatcher::add(int x,int y) {

   std::vector<int> l_vec;

   for(auto& l_elem : this->a_list_interface) {
     l_vec.push_back(l_elem->add(x,y));
   }

   return l_vec;
  }

 /////////////////////////////////////////////////////////////////////////////
 //                               GET and SET                               //
 /////////////////////////////////////////////////////////////////////////////
  std::vector<int> I1_Dispatcher::get_a() const {
   std::vector<int> l_vec;

   for(auto& l_elem : this->a_list_interface) {
     l_vec.push_back(l_elem->get_a());
   }

   return l_vec;
}

 void I1_Dispatcher::set_a(const int a) {
  for(auto& l_elem : this->a_list_interface) {
    l_elem->set_a(a);
   }
 }
