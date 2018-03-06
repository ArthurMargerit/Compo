#pragma once
#include <iostream>
#include <thread>
#include <fstream>
#include "a.hpp"


template<typename T>
class Link
{
public:
  Link()
  {
    std::cout << "Start link\n";
  }

  virtual ~Link(){
    std::cout << "End link\n";
  }
};

template<typename T>
class Direct_link : public Link<T>
{
private:
  T& p;
  T*& r;

public:
  Direct_link(T& p, T*& r):p(p),r(r)
  {
    std::cout << "Start DIRECT link\n";
    r = &p;
  }

  virtual ~Direct_link()
  {
    // destroy the link
    r = NULL;
    std::cout << "End DIRECT link\n";
  }
};

template<typename T,typename T_FAKE>
class Fifo_link_send : public Link<T>
{
  T** a;
  T_FAKE s;

  std::ofstream param_send;
  std::ifstream return_rec;

public:
  Fifo_link_send(T** a, std::string param, std::string return_a)
    :a(a),
     param_send(param.c_str()),
     return_rec(return_a.c_str()),
     s(this->param_send, this->return_rec)
  {
    std::cout << "Start send\n";
    *a = &this->s;

    this->param_send << "OK" << std::endl;

    std::string result;
    do{
        this->return_rec >> result;
      } while (result != "OK");
  }

  virtual
  ~Fifo_link_send()
  {
    std::cout << "End send\n";
  }

};

template<typename T>
class Fifo_link_rec : public Link<T>
{
  T* a;

  std::ifstream param_rec;
  std::ofstream return_send;

  std::thread waiter;

public:

  Fifo_link_rec(T* a,
                std::string param,
                std::string return_a)
    :a(a),
     param_rec(param.c_str()),
     return_send(return_a.c_str())
  {
    std::cout << "Start rec\n";

    std::string l;
    do
      {
        this->param_rec >> l;
      } while (l != "OK");
    // rep

    this->return_send << "OK" << std::endl;

    this->waiter = std::thread(&Fifo_link_rec::wait_test,this);
  }

  void wait_test()
  {
    std::string st;
    while(1)
      {
        int ap;
        int bp;
        int cr;

        this->param_rec >> ap;
        this->param_rec >> bp;
        std::cout << "(" << ap << "," << bp << ")";
        cr = a->test(ap,bp);
        std::cout << "=>"<< cr << "\n";
        return_send << " " << cr << std::endl;
      }
  }

  virtual
  ~Fifo_link_rec()
  {
    std::cout << "End rec\n";
    this->waiter.detach();
  }
};

void link_rec(a* l);
void link_send(a** l);
std::thread link(a* p, a** r);
