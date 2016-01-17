#ifndef __COLLECTOSAP__
#define __COLLECTOSAP__

#include "square.h"

class Player;

class CollectOsap : public Square {
public:
    void landOn(Player *player);
    CollectOsap();
};

#endif

