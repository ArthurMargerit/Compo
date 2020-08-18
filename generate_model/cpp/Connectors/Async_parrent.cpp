#include "connectors/Async/Async_Connector.hpp"
#include <iostream>

namespace CompoMe {
namespace Async {
namespace {
void clear() {
  // TODO only nix systems
  std::cout << "\x1B[2J\x1B[H";
}
} // namespace
Async_Connector::Async_Connector() {}

Async_Connector::~Async_Connector() {}

void Async_Connector::state() {
  clear();
  for (auto &i_v : v) {
    std::cout << i_v->state() << "\n";
  }
  std::cout << std::flush;
}

void Async_Connector::step() {
  auto i_v = std::begin(v);
  while (i_v != std::end(v)) {
    if ((*i_v)->timeout()) {
      // TODO send error message
      delete (*i_v);
      v.erase(i_v);
      continue;
    }

    if ((*i_v)->finish()) {
      (*i_v)->release();

      delete (*i_v);
      v.erase(i_v);
      continue;
    } else {
      i_v++;
    }
  }
}

int Async_Connector::add(Async_Call_g *p_call) {
  this->v.push_back(p_call);
  return 0;
}

bool Async_Connector::empty() { return this->v.empty(); }

} // namespace Async
} // namespace CompoMe
