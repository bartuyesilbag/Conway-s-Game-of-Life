#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

class gameOfLife
{
public:
  gameOfLife() {}
  ~gameOfLife() {}
  CONTAINER execute(CONTAINER *c);
};

CONTAINER gameOfLife::execute(CONTAINER *c)
{
  return *c;
}

#endif