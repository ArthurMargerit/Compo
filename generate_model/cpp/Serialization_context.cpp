#include "Serialization_context.hpp"
#include "Components/Component.hpp"
#include "Errors/Error.hpp"
#include "Structs/Struct.hpp"
#include "CompoMe/Log.hpp"

#include <utility>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

namespace CompoMe {

Serializable_Item:: ~Serializable_Item(){}

// Stream
void Serializable_Item::to_stream(std::ostream &,
                                  Serialization_context_export &) const {

  C_ERROR("to stream is not implemented but is called");
}

void Serializable_Item::from_stream(std::istream &is,
                                    Serialization_context_import &) {

  C_ERROR("from stream is not implemented but is called");
}

// Dbus
void Serializable_Item::to_dbus(DBusMessageIter &os,
                                Serialization_context_export &) const {

  C_ERROR("to dbus is not implemented but is called");
}

void Serializable_Item::from_dbus(DBusMessageIter &is,
                                  Serialization_context_import &) {

  C_ERROR("from dbus is not implemented but is called");
}

// Json
void Serializable_Item::to_json(nlohmann::json &os,
                                Serialization_context_export &) const {

  C_ERROR("to json is not implemented but is called");
}

void Serializable_Item::from_json(const nlohmann::json &is,
                                  Serialization_context_import &) {

  C_ERROR("from json is not implemented but is called");
}

void *to_pointer(std::shared_ptr<Serializable_Item> ptr) {
  std::stringstream ss;
  ss << ptr.get();
  void *r;
  ss >> r;
  return r;
}

std::pair<std::string, char> get_word(std::istream &is,
                                      std::vector<char> one_of) {
  std::stringstream ss;
  char l_c;
  while (true) {
    l_c = is.peek();
    if (std::find(one_of.begin(), one_of.end(), l_c) != one_of.end()) {
      break;
    }
    ss << (char)is.get();
  }

  return std::make_pair(ss.str(), l_c);
}

std::string get_type(std::istream &is) {
  int tg = is.tellg();

  while (is.peek() != '{') {
    C_ERROR("wrong start: '" , (int)is.get(), "'");
    return "None";
  }
  is.get();

  while (is.peek() != '}') {
    auto k = get_word(is, {':', '}'});
    is.get();
    auto s = get_word(is, {',', '}'});
    is.get();

    if (k.first == "type") {
      is.seekg(tg);
      return s.first;
    }
  }

  is.seekg(tg);
  return "None";
}

std::string get_addr(std::istream &is) {
  int tg = is.tellg();

  while (is.peek() != '{') {
    C_ERROR("wrong start: '", (int)is.get(), "'");
    return "None";
  }
  is.get();

  while (is.peek() != '}') {
    auto k = get_word(is, {':', '}'});
    is.get();
    auto s = get_word(is, {',', '}'});
    is.get();

    if (k.first == "addr") {
      is.seekg(tg);
      return s.first;
    }
  }

  is.seekg(tg);
  return "None";
}

void p_from_stream(std::istream &is, Serializable_Item *&p_c,
                   Serialization_context_import &p_ctx) {
  if (is.peek() != '*') {
    C_ERROR("stream is not a pointer");
    throw "stream is not a pointer";
  }
  is.get();

  if (is.peek() != '(') {
    C_ERROR("is not a right addr declaration start");
    throw "is not a right addr declaration start";
  }
  is.get();

  void *addr;
  is >> addr;
  p_ctx.get_loc(addr, p_c);

  if (is.peek() != ')') {
    C_ERROR("is not a right addr declaration end");
    throw "is not a right addr declaration end";
  }
  is.get();
}

void p_from_stream(std::istream &is, std::shared_ptr<Serializable_Item> &p_c,
                   Serialization_context_import &p_ctx) {
  if (is.peek() != '*') {
    C_ERROR("stream is not a pointer");
    throw "stream is not a pointer";
  }
  is.get();

  if (is.peek() != '(') {
    C_ERROR("is not a right addr declaration start");
    throw "is not a right addr declaration start";
  }
  is.get();

  void *addr;
  is >> addr;
  p_ctx.get_loc(addr, p_c);

  if (is.peek() != ')') {
    C_ERROR("is not a right addr declaration end");
    throw "is not a right addr declaration end";
  }
  is.get();
}

void p_to_stream(std::ostream &os, const Serializable_Item *c,
                 Serialization_context_export &p_ctx) {
  os << "*(" << (void *)c << ")";
  p_ctx.want(c);
}

void p_to_stream(std::ostream &os, const std::shared_ptr<Serializable_Item> c,
                 Serialization_context_export &p_ctx) {
  p_to_stream(os, c.get(), p_ctx);
}

///////////////////////////////////////////////////////////////////////////////
//                        SERIALIZATION IMPORT CONTEXT                       //
///////////////////////////////////////////////////////////////////////////////
Serialization_context_import::Serialization_context_import() {
  this->ext2local[NULL] = {nullptr, nullptr};
}

Serialization_context_import::~Serialization_context_import() {}

void Serialization_context_import::inscribe(void *p_ext,
                                            Serializable_Item *p_loc) {

  this->ext2local[p_ext] = {p_loc, nullptr};
  if (is_wanted_loc(p_ext)) {
    for (auto &at : this->want_loc[p_ext]) {
      *at = p_loc;
    }
    this->want_loc.erase(p_ext);
  }

  if (is_wanted_loc_sp(p_ext)) {
    std::shared_ptr<Serializable_Item> l_sp(p_loc);
    this->ext2local[p_ext].second = l_sp;
    for (auto &at : this->want_loc_sp[p_ext]) {
      *at = l_sp;
    }

    this->want_loc_sp.erase(p_ext);
  }
}

bool Serialization_context_import::is_inscribe(void *p_ext) {
  auto f = this->ext2local.find(p_ext);
  return f != this->ext2local.end();
}

void Serialization_context_import::get_loc(void *p_ext,
                                           Serializable_Item *&p_at) {
  if (is_inscribe(p_ext)) {
    p_at = this->ext2local[p_ext].first;
    return;
  }

  this->want_loc[p_ext].push_back(&p_at);
  return;
}

void Serialization_context_import::get_loc(
    void *p_ext, std::shared_ptr<Serializable_Item> &p_at) {
  if (is_inscribe(p_ext)) {
    if (this->ext2local[p_ext].second == nullptr) {
      std::shared_ptr<Serializable_Item> l_sp(this->ext2local[p_ext].first);
      this->ext2local[p_ext].second = l_sp;
    }
    p_at = this->ext2local[p_ext].second;
    return;
  }

  this->want_loc_sp[p_ext].push_back(&p_at);
  return;
}

bool Serialization_context_import::is_wanted_loc(void *p_ext) {
  auto f = this->want_loc.find(p_ext);
  return f != this->want_loc.end();
}

bool Serialization_context_import::is_wanted_loc_sp(void *p_ext) {
  auto f = this->want_loc_sp.find(p_ext);
  return f != this->want_loc_sp.end();
}

void Serialization_context_import::import_wanted(std::istream &is) {
  while (this->want_loc.size() != 0 || this->want_loc_sp.size() != 0) {
    std::string t = get_type(is);
    Serializable_fac::get_inst().build(t, is, *this);
  }
  return;
}

///////////////////////////////////////////////////////////////////////////////
//                        SERIALIZATION EXPORT CONTEXT                       //
///////////////////////////////////////////////////////////////////////////////
Serialization_context_export::Serialization_context_export() {
  this->declare_ext_s.push_back(NULL);
}

Serialization_context_export::~Serialization_context_export() {}

void Serialization_context_export::want(const Serializable_Item *p_s) {
  if (nullptr == p_s || this->is_declare(p_s)) {
    return;
  }

  this->declare_want_s.push_back(p_s);
}

void Serialization_context_export::export_wanted(std::ostream &os) {
  while (this->declare_want_s.size() != 0) {
    (*this->declare_want_s.begin())->to_stream(os, *this);
  }
}

bool Serialization_context_export::is_declare(const Serializable_Item *p_c) {
  auto f =
      std::find(this->declare_ext_s.begin(), this->declare_ext_s.end(), p_c);
  return f != this->declare_ext_s.end();
}

bool Serialization_context_export::is_wanted(const Serializable_Item *p_ext) {
  auto f = std::find(this->declare_want_s.begin(), this->declare_want_s.end(),
                     p_ext);
  return f != this->declare_want_s.end();
}

void Serialization_context_export::declare(const Serializable_Item *p_s) {

  if (this->is_wanted(p_s)) {
    this->declare_want_s.erase(std::remove(this->declare_want_s.begin(),
                                           this->declare_want_s.end(), p_s),
                               this->declare_want_s.end());
  }

  this->declare_ext_s.push_back(p_s);
}

// operator
std::ostream &operator<<(std::ostream &os, const Serializable_Item *c) {
  Serialization_context_export p_ctx;
  p_to_stream(os, c, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::ostream &operator<<(std::ostream &os,
                         const std::shared_ptr<Serializable_Item> &c) {
  Serialization_context_export p_ctx;
  p_to_stream(os, c, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, Serializable_Item *&c) {
  Serialization_context_import p_ctx;
  p_from_stream(is, c, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

std::istream &operator>>(std::istream &is,
                         std::shared_ptr<Serializable_Item> &c) {
  Serialization_context_import p_ctx;
  p_from_stream(is, c, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

std::string Serializable_Item::to_string() const {
  std::stringstream ss;
  Serialization_context_export l_ctx;
  this->to_stream(ss, l_ctx);
  return std::string(ss.str());
}

void Serializable_Item::from_string(std::string &str) {
  std::stringstream ss(str);
  Serialization_context_import l_ctx;
  this->from_stream(ss, l_ctx);
}

Serializable_fac::Serializable_fac() {}

Serializable_fac::~Serializable_fac() {}

void Serializable_fac::subscribe(const std::string &ss,
                                 Serializable_fac::Build_fac_f v,
                                 Serializable_fac::Build_fac_f_sp v_sp) {
  this->childs[ss] = std::make_pair(v, v_sp);
}

Serializable_Item *
Serializable_fac::build(const std::string &p_type, std::istream &p_stream,
                        Serialization_context_import &p_ctx) {

  if (p_type == "CompoMe::Struct" || p_type == "CompoMe::Error" || p_type == "CompoMe::Component") {
    C_ERROR(p_type, " is virtual" );
    return NULL;
  }

  auto f = this->childs.find(p_type);

  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream, p_ctx);
  }

  C_ERROR("Error: of ", p_type , " build" );
  C_ERROR("Your type \"" , p_type
          , "\" is not include or not init as a child." );
  for(auto a : this->childs){
    C_ERROR(" - ", a.first , "\n");
    }

  return NULL;
}

std::shared_ptr<Serializable_Item>
Serializable_fac::build_sp(const std::string &p_type, std::istream &p_stream) {

  if (p_type == "Struct" || p_type == "Error" || p_type == "Component") {
    C_ERROR(p_type, " is virtual" );
    return NULL;
  }

  auto f = this->childs.find(p_type);

  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  C_ERROR("Error: of Struct* build" );
  C_ERROR("Your type \"", p_type
          , "\" is not include or not init as a child." );

  return std::shared_ptr<CompoMe::Struct>();
}


  std::ostream& operator<<(std::ostream& os, const Serializable_Item& c){
    CompoMe::Serialization_context_export ctx_imp;
    c.to_stream(os, ctx_imp);
    ctx_imp.export_wanted(os);
    return os;
  }

  std::istream& operator>>(std::istream& is, Serializable_Item& c){
    CompoMe::Serialization_context_import ctx_exp;
    c.from_stream(is,ctx_exp);
    ctx_exp.import_wanted(is);
    return is;
  }

} // namespace CompoMe
