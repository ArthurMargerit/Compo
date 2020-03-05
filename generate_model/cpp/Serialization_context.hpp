#pragma once
#include <functional>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class Struct;

class Serialization_context {
  using Struct_v = std::vector<Struct**>;

  std::map<void *, Struct *> ext2local;
  std::map<void* , Struct_v> want_loc;
  std::vector<const Struct *> declare_ext;
  std::vector<const Struct *> declare_want;

public:
  Serialization_context();
  virtual ~Serialization_context();

  void inscribe(void *p_ext, Struct *p_loc);
  bool is_inscribe(void *p_ext);

  bool is_wanted_loc(void*);
  void get_loc(void *p_ext, Struct*& p_loc);
  //  void get_loc(void *p_ext, std::shared_ptr<Struct>& p_loc);

  void want(const Struct *t);
  void declare(const Struct *p_ext);
  bool is_declare(const Struct *p_ext);
  bool is_wanted(const Struct *p_ext);
  
  void export_wanted(std::ostream &os);
  void import_wanted(std::istream &os);
};
