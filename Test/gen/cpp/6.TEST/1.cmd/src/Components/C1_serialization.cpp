#include "Components/C1.hpp"
#include "Serialization_context.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const C1 &c) {
  Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, C1 &c) {
  Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
std::ostream &C1::to_stream(std::ostream &os,
                            Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "C1";

  os << ",provide:{";

  os << "p1:";
  this->p1.save(os);

  os << "}"; // // os << "}";
  return os;
}

std::istream &C1::from_stream(std::istream &is,
                              Serialization_context_import &p_ctx) {
  // TODO
  return is;
}
