#include "Interface1_impl.hpp"

Interface1_impl::Interface1_impl() {}

Interface1_impl::~Interface1_impl() {}

void Interface1_impl::f1() {}
void Interface1_impl::f2(i32 a, i32 b) {}

i32 Interface1_impl::f3(i32 a, i32 b, i32 c) { return a + b + c; }

void Interface1_impl::set_data1(const i32 &d) {this->data1 = d;}
i32 Interface1_impl::get_data1() const {return this->data1;}

i32 Interface1_impl::get_data2() const {return this->data2;}
void Interface1_impl::set_data2(const i32 &d) {this->data2 = d;}
