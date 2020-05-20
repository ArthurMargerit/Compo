// #pragma once
// #include "Errors/Error.hpp"

// #include <istream>
// #include <functional>
// #include <utility>
// #include <map>


// // SINGLETON
// class Error_fac {
// public:
//   using Build_fac_f =
//       std::function<Error *(const std::string &, std::istream &)>;

//   using Build_fac_f_sp = std::function<std::shared_ptr<Error>(
//       const std::string &, std::istream &)>;

//   static Error_fac &get_inst() {
//     static Error_fac inst;
//     return inst;
//   }

//   virtual Error *build(const std::string &p_type, std::istream &p_stream);
//   virtual std::shared_ptr<Error> build_sp(const std::string &p_type,
//                                           std::istream &p_stream);
//   virtual void subscribe(const std::string &ss, Build_fac_f v,
//                          Build_fac_f_sp v_sp);

// private:
//   Error_fac();
//   virtual ~Error_fac();

//   std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
// };
