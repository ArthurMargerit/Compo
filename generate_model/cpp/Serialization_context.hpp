#pragma once
#include <functional>
#include <map>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

struct Struct;

class Serialization_context {
  using Struct_v_p = std::vector<Struct **>;
  using Struct_v_sp = std::vector<std::shared_ptr<Struct> *>;
  using Struct_p_and_sp = std::pair<Struct *, std::shared_ptr<Struct>>;

  std::map<void *, Struct_p_and_sp> ext2local;
  std::map<void *, Struct_v_p> want_loc;
  std::map<void *, Struct_v_sp> want_loc_sp;

  std::vector<const Struct *> declare_ext;
  std::vector<const Struct *> declare_want;

public:
  Serialization_context();
  virtual ~Serialization_context();

  void inscribe(void *p_ext, Struct *p_loc);
  bool is_inscribe(void *p_ext);
  bool is_sptr(void *p_ext);

  bool is_wanted_loc(void *);
  bool is_wanted_loc_sp(void *p_ext);

  void get_loc(void *p_ext, Struct *&p_loc);
  void get_loc(void *p_ext, std::shared_ptr<Struct> &p_at);

  void want(const Struct *t);
  void declare(const Struct *p_ext);
  bool is_declare(const Struct *p_ext);
  bool is_wanted(const Struct *p_ext);
  void export_wanted(std::ostream &os);
  void import_wanted(std::istream &os);
};

std::string get_type(std::istream &is);
std::string get_addr(std::istream &is);
void *to_pointer(std::shared_ptr<Struct> ptr);
