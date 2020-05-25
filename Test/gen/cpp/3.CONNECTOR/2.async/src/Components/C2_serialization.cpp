#include "Components/C2.hpp"
#include "Serialization_context.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const C2 &c) {
  Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, C2 &c) {
  Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
std::ostream &C2::to_stream(std::ostream &os,
                            Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "C2";

  os << ",provide:{";

  os << "back_call:";
  this->back_call.save(os);

  os << "}";
  os << ",require:{";

  os << "call:";
  this->call.to_stream(os, p_ctx);

  os << "}"; // // os << "}";
  return os;
}

std::istream &C2::from_stream(std::istream &is,
                              Serialization_context_import &p_ctx) {
  // TODO
  return is;
}
