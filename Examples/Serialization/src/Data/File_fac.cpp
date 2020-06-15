#include "Data/File_fac.hpp"
#include "Data/File.hpp"

#include <iostream>

File_fac::File_fac() {
  std::cout << "--File_fac build"
            << "\n";
  this->init();
}

File_fac::~File_fac() {}

File *File_fac::build(const std::string &p_type, std::istream &p_stream,
                      Serialization_context_import &p_ctx) {

  if (p_type == "File") {
    // void* l_addr = get_addr(is);
    // if(p_ctx.is_share_ptr(l_addr)) {
    //   std::shared_ptr<{NAME}}> b = std::make_shared<File>();
    //   b->from_stream(p_stream, p_ctx);
    // } else {
    File *b = new File();
    b->from_stream(p_stream, p_ctx);
    //    }
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream, p_ctx);
  }

  std::cerr << "Error: of Serializable* build "
            << "Your type \"" << p_type
            << "\" is not include or not init as a child." << std::endl;

  return NULL;
}

std::shared_ptr<File> File_fac::build_sp(const std::string &p_type,
                                         std::istream &p_stream) {

  if (p_type == "File") {
    auto b = std::make_shared<File>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  std::cerr << "Error: of std::shared_ptr<File> build "
            << "Your type \"" << p_type
            << "\" is not include or not init as a child." << std::endl;

  return std::shared_ptr<File>();
}

void File_fac::init() {

  Serializable_fac::Build_fac_f f = [](const std::string &str,
                                       std::istream &p_s,
                                       Serialization_context_import &l_ctx) {
    return dynamic_cast<Serializable_Item *>(
        File_fac::get_inst().build(str, p_s, l_ctx));
  };
  Serializable_fac::Build_fac_f_sp f_sp = [](const std::string &str,
                                             std::istream &p_s) {
    return File_fac::get_inst().build_sp(str, p_s);
  };

  Serializable_fac::get_inst().subscribe("File", f, f_sp);
}

void File_fac::subscribe(const std::string &ss, Build_fac_f v,
                         Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v, v_sp);

  Serializable_fac::get_inst().subscribe(ss, v, v_sp);
}
