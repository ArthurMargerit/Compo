#pragma once
#include <map>

class Serialization_context {
  std::map<void *, void *> ext2local;

public:
  Serialization_context();
  virtual ~Serialization_context();
  void inscribe(void * p_ext, void * p_loc);
  bool is_decrare(void * p_ext);
  void* get_loc(void * p_ext);
};
