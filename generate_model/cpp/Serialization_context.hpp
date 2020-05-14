#pragma once
#include <functional>
#include <map>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

struct Struct;
struct Error;
class Interface;
class Component;
class Link;
class Deployment;

enum e_compo_kind {
  E_COMPO_KIND_OTHER = 0,
  E_COMPO_KIND_STRUCT = 1,
  E_COMPO_KIND_ERROR = 2,
  E_COMPO_KIND_INTERFACE = 3,
  E_COMPO_KIND_COMPONENT = 4,
  E_COMPO_KIND_CONNECTOR = 5,
  E_COMPO_KIND_LINK = 6,
  E_COMPO_KIND_DEPLOYMENT = 7
};

struct Compo_gen_pointer {
  union {
    void *u_other;
    Struct *u_struct;
    Error *u_error;
    Interface *u_interface;
    Component *u_component;
    Link *u_link;
    Deployment *u_deployment;
  };
  e_compo_kind a_kind;
};

class Serialization_context_import {
private:
  using Struct_v_p = std::vector<Struct **>;
  using Struct_v_sp = std::vector<std::shared_ptr<Struct> *>;
  using Struct_p_and_sp = std::pair<Struct *, std::shared_ptr<Struct>>;

  std::map<void *, Struct_p_and_sp> ext2local;
  std::map<void *, Struct_v_p> want_loc;
  std::map<void *, Struct_v_sp> want_loc_sp;

public:
  Serialization_context_import();
  virtual ~Serialization_context_import();
  void import_wanted(std::istream &os);

  void get_loc(void *p_ext, Struct *&p_loc);
  void get_loc(void *p_ext, std::shared_ptr<Struct> &p_at);

  bool is_wanted_loc(void *);
  bool is_wanted_loc_sp(void *p_ext);

  void inscribe(void *p_ext, Struct *p_loc);
  bool is_inscribe(void *p_ext);
  bool is_sptr(void *p_ext);
};

class Serialization_context_export {
private:
  std::vector<const Struct *> declare_ext_s;
  std::vector<const Struct *> declare_want_s;

  std::vector<const Error *> declare_ext_e;
  std::vector<const Error *> declare_want_e;

  std::vector<const Component *> declare_ext_c;
  std::vector<const Component *> declare_want_c;
public:
  Serialization_context_export();
  virtual ~Serialization_context_export();

  void export_wanted(std::ostream &os);

  void want(const Struct *);
  void want(const Error *);
  void want(const Component *);

  void declare(const Struct *);
  void declare(const Error *);
  void declare(const Component *);

  bool is_declare(const Struct *);
  bool is_declare(const Error *);
  bool is_declare(const Component *);

  bool is_wanted(const Struct *);
  bool is_wanted(const Error *);
  bool is_wanted(const Component *);
};

std::string get_type(std::istream &is);
std::string get_addr(std::istream &is);

void *to_pointer(std::shared_ptr<Struct> ptr);
