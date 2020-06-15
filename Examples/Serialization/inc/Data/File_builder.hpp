#pragma once

#include "Data/File.hpp"

#include <memory>

class File_builder {

public:
  File_builder();
  virtual ~File_builder();

  // setter

  File_builder &set_path(const string &p_path);

  // build
  File build();
  File *build_p();
  std::shared_ptr<File> build_sp();

protected:
  void asign(File &p_name);

private:
  string path;
};
