#pragma once
#include <tuple>
#include <iostream>
#include <fstream>

template<int s,typename ... ARG>
class BT{
public:
  static  void send_type(std::ostream& out, std::tuple<ARG...>& arg)
  {

    BT<s-1, ARG ...>::send_type(out, arg);
    out << std::get<s-1>(arg) << " ";
  }

  static  void rec_type(std::istream& in, int& i,std::tuple<ARG...>& arg)
  {
    BT<s-1,ARG...>::rec_type(in, i, arg);
    in >> std::get<s-1>(arg);
  }
};


template<typename ... ARG>
class BT<0,ARG...>{
public:
  static void send_type(std::ostream& out, std::tuple<ARG ... > & arg)
  {

  }

  static  void rec_type(std::istream& in, int& i, std::tuple<ARG...>& arg)
  {
  }
};

class a
{
public:
  virtual int test(int a, int b)
  {
    std::cout << "call" << "\n";
    return a+b;
  }
};

class a_send : public a
{
public:
  std::ofstream& out;
  std::ifstream& in;

  enum FUNCTION_ID{
    TEST_A,
    TEST_B,
    TEST_C
  };

  a_send(std::ofstream& p_out, std::ifstream& p_in):out(p_out),in(p_in)
  {

  }

  template<typename T, int NB_ARG,typename ... ARG>
  T send(FUNCTION_ID id,
         std::tuple<ARG...> arg)
  {

    //send arg
    this->out << "START "<<id << " " << NB_ARG ;
    BT<NB_ARG,
       ARG ...>::send_type(out,
                           arg);

    this->out << "END"<< std::endl;


    T result;
    this->in >> result;
    std::cout << "=>" << result << std::endl;

    return result;
  }

  virtual int test_A(int a, int b)
  {
    std::tuple<int,int> arg(a,b);
    return send<int,2>(TEST_A, arg);
  }

  virtual int test_B(int a)
  {
    std::tuple<int> arg(a);
    return send<int,1>(TEST_B, arg);
  }

  virtual int test_c(int a,int b,int c)
  {
    std::tuple<int,int,int> arg(a,b,c);
    return send<int,3>(TEST_C, arg);
  }

};

// class a_recx
// {
// public:
//   a* out;
//   std::ifstream f;

//   a_rec():f("t")
//   {

//   }

//   void wait_test(void)
//   {
//     std::string str;
//     for (int i = 0 ; i <10 ; i++){
//       this->f >> str;
//       out->test();
//     }
//   }
// };


