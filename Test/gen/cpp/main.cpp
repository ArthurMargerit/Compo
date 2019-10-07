#include "Components/C1/C1.hpp"
#include "Interfaces/Caller.hpp"
#include "Errors/MyError.hpp"

#include <sstream>

class Return_r_stream: public Return_stream {
public:
  Return_r_stream(std::ostream *os):Return_stream(os)
  {}
  Return_r_stream(std::istream *is):Return_stream(is)
  {}
  virtual void pull() {}
  virtual void end() {}

};

class Function_r_stream: public Function_stream {
public:
  Function_r_stream(std::istream *is):Function_stream(is)
  {}
  Function_r_stream(std::ostream *os):Function_stream(os)
  {}
  virtual void start() {}
  virtual void call() {}

};

int main(int argc, char *argv[]) {

  // C1::C1 c1;
  init_code();
  // auto c = c1.get_p1().get_caller();
  // Function_r_stream fs(&std::cin);
  // Return_r_stream rs(&std::cout);
  // while (true){
  //   std::cout << "\n>>>";

  //   // if closed
  //   if(! std::cin.good()){
  //     break;
  //   }

  //   // remove space
  //   while(std::cin.peek() == ' '){
  //     std::cin.get();
  //   }

  //   // valid empty
  //   if(std::cin.peek() == '\n'){
  //     std::cin.get();
  //     continue;
  //   }

  //   // call
  //   c->call(fs,rs);
  // }

  Function_r_stream fs(&std::cout);
  Return_r_stream rs(&std::cin);
  // MyError m;
  // std::cout << m;
  Lapin *l = NULL;
  Interface *k = get_build_fake(l)(fs, rs);
  l = (Lapin *)k;
  try{
  std::cout << "return: " << l->add(1, 3) << std::endl;
  }catch(char const * e){
    std::cout << e << std::endl;
  }catch(Error * e){
    std::cout << e << std::endl;
  }
  catch(std::string& e){
    std::cout <<"std::string" <<e << std::endl;
  }

  // Error *e = NULL;
  // std::stringstream ss("*{type:MyError}");
  // std::cout << e;
  // ss >> e;
  // std::cout << e;
  

  return 0;
}
