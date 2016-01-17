#ifndef __SLC__
#define __SLC__
#include "square.h"

class Player;

class SLC : public Square {
public:
    void landOn(Player *player);
    SLC();
};

#endif
