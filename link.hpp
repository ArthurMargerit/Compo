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
  std::ofstream out;
  std::ifstream in;

public:
  Fifo_link_send(T** a, std::string in, std::string out):a(a),out(out.c_str()),in(in.c_str()),s(this->out,this->in)
  {
    std::cout << "Start send\n";
    *a = &this->s;
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
  std::ifstream in;
  std::ofstream out;

public:

  Fifo_link_rec(T* a,
                std::string in,
                std::string out):a(a),
                                 in(in.c_str()),
                                 out(out.c_str())
  {
    std::cout << "Start rec\n";
  }

  void wait_test()
  {
    std::string st;
    while(1)
      {
        in >> st;
        auto retu = a->test();
        out << retu << std::endl;
      }


  }

  virtual
  ~Fifo_link_rec()
  {
    std::cout << "End rec\n";
  }
};

void link_rec(a* l);
void link_send(a** l);
std::thread link(a* p, a** r);
