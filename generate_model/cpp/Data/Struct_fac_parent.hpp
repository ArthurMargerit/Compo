// #pragma once
// #include "Data/Struct.hpp"
// #include "Serialization_context.hpp"

// #include <functional>
// #include <istream>
// #include <memory>
// #include <utility>
// #include <map>

// // SINGLETON
// class Struct_fac {
// public:
//   using Build_fac_f =
//     std::function<Struct *(const std::string &, std::istream &, Serialization_context_import&)>;
//   using Build_fac_f_sp =
//     std::function<std::shared_ptr<Struct>(const std::string &, std::istream &)>;

//   static Struct_fac &get_inst() {
//     static Struct_fac inst;
//     return inst;
//   }

//   virtual Struct *build(const std::string &p_type, std::istream &p_stream, Serialization_context_import&);
//   virtual std::shared_ptr<Struct> build_sp(const std::string &p_type, std::istream &p_stream);
//   virtual void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp );

// private:
//   Struct_fac();
//   virtual ~Struct_fac();

//   std::map<std::string, std::pair<Build_fac_f,Build_fac_f_sp> > childs;
// };
