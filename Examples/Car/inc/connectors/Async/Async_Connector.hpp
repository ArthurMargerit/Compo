
#include "connectors/Async/Async_Call.hpp"
#include <sstream>
#include <vector>

namespace CompoMe {
namespace Async {

class Async_Connector {
  std::vector<Async_Call_g *> v;

public:
  Async_Connector();
  virtual ~Async_Connector();

  void state();
  void step();
  bool empty();
  int add(Async_Call_g *p_call);

protected:
};

} // namespace Async
} // namespace CompoMe