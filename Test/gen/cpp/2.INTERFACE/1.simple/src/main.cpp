#include "Interfaces/Empty/Empty.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IC/IC.hpp"
#include "Interfaces/ID/ID.hpp"
#include "Interfaces/IE/IE.hpp"


class IA_r:public IA
{
public:
  IA_r();
  virtual ~IA_r();

};

class IB_r:public IB
{
public:
  IA_r();
  virtual ~IA_r();
  override int f1(){}
  override int f2(int p1){}

};


int main(int argc, char *argv[])
{
  
  return 0;
}
