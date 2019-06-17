

// #include <iostream>
// #include <string>

#include "Components/C_t2p/C_t2p.hpp"
#include "utils/Shell.hpp"


// #include "Interfaces/Function_stream.hpp"
// #include "Components/C1/C1.hpp"
// #include "Components/C2/C2.hpp"
// #include "Interfaces/Caller.hpp"

// #include <functional>
// #include <thread>
// #include <mutex>


// template<typename R, typename ... T>
// std::thread* async_call(void(call_back)(R), R(f)(T...) , T... args ){
//   auto t = new std::thread([f,call_back,args...](){
//                 R r = f(args...);
//                 call_back(r);
//         });
//   return t;
// }

// #include <vector>
// #include <functional>

// template<typename T>
// class Dispatcher
// {
// public:
//   std::vector<T*> interfaces;
//   void add(T* t) {
//     interfaces.push_back(t);
//   }

//   template<typename R,typename ... ARG>
//   std::vector<R> call( std::function< R(T*,ARG...)> f ,ARG ... args) {
//     std::vector<R> r;
//     for (auto &p : this->interfaces ) {
//       R r_v = f(p,args...);
//       r.push_back(r_v);
//     }
//     return r;
//   }

//   template<typename ... ARG>
//   void call(std::function<void(T*,ARG...)> f, ARG ... args) {
//     for (auto &p : this->interfaces ) {
//       f(p,args...);
//     }
//     return;
//   }
// };


// template<typename T>
// class Distribute
// {
// public:
//   std::vector<T*> interfaces;
//   int a_i;

//   void add(T* t) {
//     interfaces.push_back(t);
//   }

//   template<typename R,typename ... ARG>
//   R call( std::function< R(T*,ARG...)> f ,ARG ... args) {
//     T* t = this->interfaces[this->i++];
//     R r = f(t,args...);
//     this->i = this->i%this->interfaces.size();
//     return r;
//   }

//   template<typename ... ARG>
//   void call(std::function<void(T*,ARG...)> f, ARG ... args) {
//     T* t = this->interfaces[this->i++];
//     f(t,args...);
//     this->i = this->i%this->interfaces.size();
//     return;
//   }
// };

// template<typename T>
// class Lock
// {
// public:
//   T& interface;
//   std::mutex m;

//   Lock(T& p_i):interface(p_i){}

//   template<typename R,typename ... ARG>
//   R call( std::function< R(T*,ARG...)> f ,ARG ... args) {
//     std::lock_guard<std::mutex> lock(this->m);
//     R r = f(this->interface,args...);
//     return r;
//   }

//   template<typename ... ARG>
//   void call(std::function<void(T*,ARG...)> f, ARG ... args) {
//     std::lock_guard<std::mutex> lock(this->m);
//     f(this->interface,args...);
//     return;
//   }
// };

// template<typename T>
// class Handler
// {
// public:
//   std::function<bool(std::string&, Interface&, void*, void*)> a_before_f;
//   std::function<bool(std::string&, Interface&, void*, void*)> a_after_f;

// public:
//   T& interface;
//   Handler(T& p_i):interface(p_i){}


//   template<typename R,typename ... ARG>
//   R call(std::string &name, std::function< R(T*,ARG...)> f ,ARG ... args) {
//     std::tuple<ARG...>  l_args_t = std::make_tuple(args...);

//     // BEFORE /////////////////////////////////////////////////////////////////
//     R r_b;
//     bool l_b = this->a_before_f(name, this->interface, &l_args_t,&r_b);
//     if(!l_b) {
//       return r_b;
//     }

//     // MAIN ///////////////////////////////////////////////////////////////////
//     R r = f(&this->interface,args...);

//     // AFTER //////////////////////////////////////////////////////////////////
//     R r_a = r;
//     bool l_a = this->a_after_f(name, this->interface, &l_args_t, &r_a);
//     if(!l_a) {
//       return r_a;
//     }

//     return r;
//   }

//   template<typename ... ARG>
//   void call(std::function<void(T*,ARG...)> f, ARG ... args) {
//     f(this->interface,args...);
//     return;
//   }
// };

// int a_cb(int v){
//   return v+1;
// }

// void end_cb(int a){
//   std::cout <<"-- end --"<< a   << "\n";
//   if(a != 10){
//     auto t = async_call(end_cb,a_cb,a);
//     t->join();
//     delete t;
//     std::cout << "a" << a << "\n";
//   }
// }

// int add(int a,int b){return a+b;}

// bool b(std::string name, Interface &i, void *p_v, void *p_r) {
//   std::tuple<int, int> *t = (std::tuple<int, int> *)p_v;

//   std::cout << &i << " b: " << name << " " << std::get<0>(*t) << ","
//             << std::get<1>(*t) << "\n";

//   return std::get<1>(*t) % 3 == 0;
// }

// bool a(std::string name, Interface &i, void *p_v, void *p_r) {
//   std::tuple<int, int> *t = (std::tuple<int, int> *)p_v;
//   int *v = (int *)p_r;

//   if (*v % 2 == 0) {
//     *v = 0;
//   }

//   std::cout << &i << " a: " << name << " " << std::get<0>(*t) << ","
//             << std::get<1>(*t) << " => " << *v << "\n";

//   return true;
// }

int main(int argc, char *argv[])
{
  C_t1p::C_t1p c;

  // shell(std::cin, std::cout, c.get_i_p2());
  // std::cout << c.get_i_p2().get_sa() << "\n";

  shell(std::cin, std::cout, c.get_i_p());
  std::cout << c.get_i_p().get_sa() << "\n";

  // C1::C1 c1;
  // c1.configuration();

  // Handler<I1> h(c1.i_p);
  // h.a_before_f = b;
  // h.a_after_f = a;
  // std::string name = "add";
  // std::function< int (I1*,int ,int)> f1 = &I1::add;
  // for (int i = 0; i < 10; ++i) {
  //   h.call(name,f1,1,i);
  // }


  // C2::C2 c2;
  // c1.configuration();


  // Dispatcher<I1> d;

  // d.add(&c1.i_p);
  // d.add(&c2.i1_p);

  // std::function< int (I1*,int ,int)> f1 = &I1::add;

  // auto a = d.call(f1,1,10);
  // for(auto &b : a) {
  //   std::cout << b  << "\n";
  // }

  // c1.step();

  // a = d.call(&I1::add,1,2);
  // for(auto &b : a) {
  //   std::cout << b  << "\n";
  // }

  //  shell(std::cin, std::cout, c1.i_p);
  //  end_cb(0);

  return 0;
}
