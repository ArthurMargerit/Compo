#include "Serialization_context.hpp"

#include "Data/Struct.hpp"
#include "Data/Struct_fac.hpp"
#include <algorithm>
#include <iostream>

void *to_pointer(std::shared_ptr<Struct> ptr) {
  std::stringstream ss;
  ss << ptr.get();
  void *r;
  ss >> r;
  return r;
}

std::string get_type(std::istream &is) {
  int tg = is.tellg();

  while (is.peek() != '{') {
    std::cerr << "wrong start: '" << (char)is.get() << "'";
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
    std::cerr << "wrong start: '" << (char)is.get() << "'";
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

///////////////////////////////////////////////////////////////////////////////
//                        SERIALIZATION IMPORT CONTEXT                       //
///////////////////////////////////////////////////////////////////////////////
Serialization_context_import::Serialization_context_import() {
  this->ext2local[NULL] = {nullptr, nullptr};
}

Serialization_context_import::~Serialization_context_import() {}

void Serialization_context_import::inscribe(void *p_ext, Struct *p_loc) {
  // if (this->is_inscribe(p_ext)) {
  //   throw "Double inscribe";
  // }

  this->ext2local[p_ext] = {p_loc, nullptr};
  if (is_wanted_loc(p_ext)) {

    for (auto &at : this->want_loc[p_ext]) {
      *at = p_loc;
    }

    this->want_loc.erase(p_ext);
  }

  if (is_wanted_loc_sp(p_ext)) {
    std::shared_ptr<Struct> l_sp(p_loc);
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

void Serialization_context_import::get_loc(void *p_ext, Struct *&p_at) {
  if (is_inscribe(p_ext)) {
    p_at = this->ext2local[p_ext].first;
    return;
  }

  this->want_loc[p_ext].push_back(&p_at);
  return;
}

void Serialization_context_import::get_loc(void *p_ext,
                                    std::shared_ptr<Struct> &p_at) {
  if (is_inscribe(p_ext)) {
    if (this->ext2local[p_ext].second == nullptr) {
      std::shared_ptr<Struct> l_sp(this->ext2local[p_ext].first);
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
    Struct_fac::get_inst().build(t, is, *this);
  }
  return;
}

///////////////////////////////////////////////////////////////////////////////
//                        SERIALIZATION EXPORT CONTEXT                       //
///////////////////////////////////////////////////////////////////////////////
Serialization_context_export::Serialization_context_export() {
  this->declare_ext.push_back(NULL);
}

Serialization_context_export::~Serialization_context_export() {}

void Serialization_context_export::want(const Struct *t) {
  if (NULL == t || this->is_declare(t)) {
    return;
  }

  this->declare_want.push_back(t);
}

void Serialization_context_export::export_wanted(std::ostream &os) {
  while (this->declare_want.size() != 0) {
    (*this->declare_want.begin())->to_stream(os, *this);
  }
}

bool Serialization_context_export::is_declare(const Struct *p_ext) {
  auto f = std::find(this->declare_ext.begin(), this->declare_ext.end(), p_ext);
  return f != this->declare_ext.end();
}

bool Serialization_context_export::is_wanted(const Struct *p_ext) {
  auto f =
    std::find(this->declare_want.begin(), this->declare_want.end(), p_ext);
  return f != this->declare_want.end();
}

void Serialization_context_export::declare(const Struct *p_ext) {
  // if (this->is_declare(p_ext)) {
  //   throw "Double declaration";
  // }

  if (this->is_wanted(p_ext)) {
    this->declare_want.erase(std::remove(this->declare_want.begin(),
                                         this->declare_want.end(), p_ext),
                             this->declare_want.end());
  }

  this->declare_ext.push_back(p_ext);
}
