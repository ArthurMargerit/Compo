#pragma once

#include <iostream>
#include <fstream>
class a
{
public:
  virtual void test(void)
  {
    std::cout << " lapin "<< this  << "\n";
  }
};

class a_send : public a
{
public:
  std::ofstream& out;
  std::ifstream& in;

  a_send(std::ofstream& p_out, std::ifstream& p_in):out(p_out),in(p_in)
  {

  }

  virtual  void test(void)
  {
    std::string result;
    this->out << std::endl;
    this->in  >> result;

  }
};

class a_rec
{
public:
  a* out;
  std::ifstream f;

  a_rec():f("t")
  {

  }

  void wait_test(void)
  {
    std::string str;
    for (int i = 0 ; i <10 ; i++){
      this->f >> str;
      out->test();
      std::cout << "call "<< i << str << "\n";
    }
  }
};


