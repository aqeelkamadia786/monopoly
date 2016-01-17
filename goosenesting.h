#ifndef __GOOSENESTING__
#define __GOOSENESTING__
#include "square.h"

class Player;

class GooseNesting : public Square {
public:
    void landOn(Player *player);
    GooseNesting();
};

#endif

