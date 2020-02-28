#include <Serialization_context.hpp>

Serialization_context::Serialization_context() {
  // NULL is the same in both target
  this->ext2local[NULL] = NULL;
}

Serialization_context::~Serialization_context() {}

void Serialization_context::inscribe(void *p_ext, void *p_loc) {
  if (is_decrare(p_ext)) {
    throw "Double inscribe";
  }

  this->ext2local[p_ext] = p_loc;
}

bool Serialization_context::is_decrare(void *p_ext) {
  auto f = this->ext2local.find(p_ext);
  return f != this->ext2local.end();
}

void *Serialization_context::get_loc(void *p_ext) {
  return this->ext2local[p_ext];
}
