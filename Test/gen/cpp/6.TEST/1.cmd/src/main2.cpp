#include "Components/C1.hpp"
#include "Interfaces/Caller_stream.hpp"
#include "Errors/MyError.hpp"
#include "Errors/MyError2.hpp"

#include <sstream>

// class Return_r_stream: public Return_stream {
// public:
//   Return_r_stream(std::ostream *os):Return_stream(os)
//   {}
//   Return_r_stream(std::istream *is):Return_stream((std::istream*)&a_ss),a_is(is)
//   {}

//   std::istream *a_is;
//   std::stringstream a_ss;

//   virtual void pull() {
//     std::string s;
//     std::getline(*this->a_is,s);
//     this->a_ss << s;
//   }

//   virtual void end() {}
// };

// class Function_r_stream: public Function_stream {
// public:
//   Function_r_stream(std::istream *is):Function_stream(is)
//   {}
//   Function_r_stream(std::ostream *os):Function_stream(os)
//   {}
//   virtual void start() {}
//   virtual void call() {}

// };

int main(int argc, char *argv[]) {

  // C1::C1 c1;
  init_code();

  // Function_r_stream fs(&std::cout);
  // Return_r_stream rs(&std::cin);
  // Lapin *l = NULL;
  // Interface *k = get_build_fake(l)(fs, rs);
  // l = (Lapin *)k;

  // for(int i=0;i<3;i++){
  //   try {
  //     auto p = l->add(1, 3);
  //     std::cout << "return: " << p << std::endl;
  //   } catch (MyError& e) {
  //     std::cout << "MyError: " << e << std::endl;
  //   } catch (MyError2& e) {
  //     std::cout << "MyError2: " << e << std::endl;
  //   } catch (Error& e) {
  //     std::cout << "Error: " << &e << std::endl;
  //   } catch (std::string &e) {
  //     std::cout << "std::string" << e << std::endl;
  //   } catch (char const *e) {
  //     std::cout << e << std::endl;
  //   }
  // }

  // delete k;

  return 0;
}
