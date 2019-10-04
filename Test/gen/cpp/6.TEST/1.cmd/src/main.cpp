#include "Components/C1/C1.hpp"
#include "Interfaces/Caller.hpp"

class Return_r_stream: public Return_stream {
public:
  Return_r_stream(std::ostream *os):Return_stream(os)
  {}
  virtual void pull() {}
  virtual void end() {}

};

class Function_r_stream: public Function_stream {
public:
  Function_r_stream(std::istream *is):Function_stream(is)
  {}
  virtual void start() {}
  virtual void call() {}

};

int main(int argc, char *argv[]) {

  C1::C1 c1;

  auto c = c1.get_p1().get_caller();
  Function_r_stream fs(&std::cin);
  Return_r_stream rs(&std::cout);

  while (true){
    std::cout << "\n>>>";


    // if closed
    if(! std::cin.good()){
      break;
    }

    // remove space
    while(std::cin.peek() == ' '){
      std::cin.get();
    }

    // valid empty
    if(std::cin.peek() == '\n'){
      std::cin.get();
      continue;
    }

    // call
    c->call(fs,rs);
  }

  return 0;
}
