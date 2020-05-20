#pragma once
#include <functional>
#include <map>
#include <memory>
#include <ostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

struct Struct;
struct Error;
class Interface;
class Component;
class Link;
class Deployment;

class Serialization_context_export;
class Serialization_context_import;

struct Serializable_Item {
  virtual std::ostream &to_stream(std::ostream &,
                                  Serialization_context_export &) const = 0;
  virtual std::istream &from_stream(std::istream &is,
                                    Serialization_context_import &p_ctx) = 0;
  std::string to_string() const;
};

class Serialization_context_import {
private:
  using SI_v_p = std::vector<Serializable_Item **>;
  using SI_v_sp = std::vector<std::shared_ptr<Serializable_Item> *>;
  using SI_p_and_sp =
      std::pair<Serializable_Item *, std::shared_ptr<Serializable_Item>>;

  std::map<void *, SI_p_and_sp> ext2local;
  std::map<void *, SI_v_p> want_loc;
  std::map<void *, SI_v_sp> want_loc_sp;

public:
  Serialization_context_import();
  virtual ~Serialization_context_import();
  void import_wanted(std::istream &os);

  void get_loc(void *p_ext, Serializable_Item *&p_loc);
  void get_loc(void *p_ext, std::shared_ptr<Serializable_Item> &p_at);

  bool is_wanted_loc(void *);
  bool is_wanted_loc_sp(void *p_ext);

  void inscribe(void *p_ext, Serializable_Item *p_loc);

  bool is_inscribe(void *p_ext);
  bool is_sptr(void *p_ext);
};

class Serialization_context_export {
private:
  std::vector<const Serializable_Item *> declare_ext_s;
  std::vector<const Serializable_Item *> declare_want_s;

public:
  Serialization_context_export();
  virtual ~Serialization_context_export();

  void export_wanted(std::ostream &os);

  void want(const Serializable_Item *);
  void declare(const Serializable_Item *);
  bool is_declare(const Serializable_Item *);
  bool is_wanted(const Serializable_Item *);
};

std::string get_type(std::istream &is);
std::string get_addr(std::istream &is);
std::pair<std::string, char> get_word(std::istream &is,
                                      std::vector<char> one_of);

void *to_pointer(std::shared_ptr<Serializable_Item> ptr);

void p_to_stream(std::ostream &os, const Serializable_Item *p_c,
                 Serialization_context_export &p_ctx);
void p_to_stream(std::ostream &os, const std::shared_ptr<Serializable_Item> c,
                 Serialization_context_export &p_ctx);
void p_from_stream(std::istream &is, Serializable_Item *&p_c,
                   Serialization_context_import &p_ctx);
void p_from_stream(std::istream &is, std::shared_ptr<Serializable_Item> &p_c,
                   Serialization_context_import &p_ctx);

std::ostream &operator<<(std::ostream &os, const Serializable_Item *c);
std::ostream &operator<<(std::ostream &os,
                         const std::shared_ptr<Serializable_Item> &c);

std::istream &operator>>(std::istream &is, Serializable_Item *&c);
std::istream &operator>>(std::istream &is,
                         std::shared_ptr<Serializable_Item> &c);

template <typename T>
std::istream &operator>>(std::istream &is, std::shared_ptr<T> &c) {
  is >> (std::shared_ptr<Serializable_Item>&) c;
  return is;
}

template <typename T> std::istream &operator>>(std::istream &is, T *&c) {
  is >> (Serializable_Item*&) c;
  return is;
}



// SINGLETON
class Serializable_fac {
public:
  using Build_fac_f =
    std::function<Serializable_Item *(const std::string &, std::istream &, Serialization_context_import&)>;
  using Build_fac_f_sp =
    std::function<std::shared_ptr<Serializable_Item>(const std::string &, std::istream &)>;

  static Serializable_fac &get_inst() {
    static Serializable_fac inst;
    return inst;
  }

  virtual Serializable_Item *build(const std::string &p_type, std::istream &p_stream, Serialization_context_import&);
  virtual std::shared_ptr<Serializable_Item> build_sp(const std::string &p_type, std::istream &p_stream);
  virtual void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp );

private:
  Serializable_fac();
  virtual ~Serializable_fac();

  std::map<std::string, std::pair<Build_fac_f,Build_fac_f_sp> > childs;
};
