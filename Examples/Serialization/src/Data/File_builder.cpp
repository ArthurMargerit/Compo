
#include "Data/File_builder.hpp"
#include "Data/File_fac.hpp"

File_builder::File_builder()

    :

      path()

{}
File_builder::~File_builder() {}

File_builder &File_builder::set_path(const string &p_path) {
  this->path = p_path;
  return *this;
}

void File_builder::asign(File &p_File) { p_File.set_path(this->path); }

File File_builder::build() {
  File p_this;
  this->asign(p_this);
  return p_this;
}

File *File_builder::build_p() {
  File *p_this = new File();
  this->asign(*p_this);
  return p_this;
}

std::shared_ptr<File> File_builder::build_sp() {
  auto p_this = std::make_shared<File>();
  this->asign(*p_this);
  return p_this;
}
