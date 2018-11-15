#pragma once


class Linker
{
public:
  Linker();
  virtual ~Linker();

  virtual void step()=0;
  };
