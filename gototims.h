#ifndef __GOTOTIMS__
#define __GOTOTIMS__
#include "square.h"

class Player;

class GoToTims : public Square {
  public:
    void landOn(Player *player);
    GoToTims();
};

#endif
