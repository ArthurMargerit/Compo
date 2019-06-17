
#include "Data/Type_vec.hpp"
#include "Components/C2/C2.hpp"
#include <iostream>

// template <typename T>
// std::ostream &operator<<(std::ostream &os, const vec<T> &c) {
//   os << "[";
//   int i = 0;
//   int size = c.size();
//   for (auto &v : c) {
//     os << v;

//     i++;
//     if (i != size) {
//       os << ",";
//     }
//   }
//   os << "]";

//   return os;
// }

// #include <map>
// #include <string>
// using si = std::string;
// template <typename K, typename V> using map = std::map<K, V>;
// template <typename V> using Smap = map<si, V>;
// template <typename K> using TVmap = map<K, si>;

int main(int argc, char *argv[]) {
  vec<int> v;
  std::cout << v << "\n";
  v.push_back(1);

  std::cout << v << "\n";
  v.push_back(2);

  std::cout << v << "\n";
  v.push_back(3);

  std::cout << v << "\n";
  v.push_back(4);


  C2::C2 c2;

  //   v.push_back(1);
  //   std::cout << v << "\n";

  //   v.push_back(2);
  //   std::cout << v << "\n";

  //   v.push_back(3);
  //   std::cout << v << "\n";

  //   v.push_back(4);
  //   std::cout << v << "\n";
  //   v.pop_back();

  //   std::cout << v << "\n";
  //   v.pop_back();

  //   std::cout << v << "\n";
  //   v.pop_back();

  //   std::cout << v << "\n";
  //   v.pop_back();

  //   std::cout << v << "\n";

  //   vec<si> v1;

  //   std::cout << v1 << "\n";

  //   v1.push_back("lapin");
  //   std::cout << v1 << "\n";

  //   v1.push_back("lion");
  //   std::cout << v1 << "\n";

  //   v1.push_back("base");
  //   std::cout << v1 << "\n";

  //   v1.push_back("epic");
  //   std::cout << v1 << "\n";
  //   v1.pop_back();

  //   std::cout << v1 << "\n";
  //   v1.pop_back();

  //   std::cout << v1 << "\n";
  //   v1.pop_back();

  //   std::cout << v1 << "\n";
  //   v1.pop_back();

  //   std::cout << v1 << "\n";

  //   Smap<int> m;
  //   m["lapin"] = 1;
  //   m["lion"] = 2;
  //   m["cpp"] = 4;

  //   TVmap<int> MA;
  //   MA[1] = "1";
  //   MA[2] = "2";
  //   MA[3] = "4";

  return 0;
}
