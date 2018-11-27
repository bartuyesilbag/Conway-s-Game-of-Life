#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

using namespace std;
class gameOfLife
{
public:
  gameOfLife() {}
  ~gameOfLife() {}
  CONTAINER execute(CONTAINER *c);
};

CONTAINER gameOfLife::execute(CONTAINER *c)
{
  CONTAINER tempVector;
  tempVector = *c;
  for (int i = 0; i < tempVector.size(); i++)
  {
    for (int j = 0; j < tempVector[i].size(); j++)
    {
      int sizev1 = tempVector.size();
      int sizev2 = tempVector[i].size();
      int liveCell = 0;
      for (int m = -1; m < 2; m++)
      {
        for (int n = -1; n < 2; n++)
        {
          if (!(m == 0 && n == 0) && (i + m >= 0 && j + n >= 0) && (i + m < sizev1 && j + n < sizev2))
          {
            if (tempVector[i + m][j + n])
            {
              ++liveCell;
            }
          }
        }
      }
      if (liveCell < 2)
      {
        (*c)[i][j] = false;
      }
      else if (liveCell == 3)
      {
        (*c)[i][j] = true;
      }
      else if (liveCell > 3)
      {
        (*c)[i][j] = false;
      }
    }
  }

  return (*c);
}

#endif