#ifndef __TUITION__
#define __TUITION__
#include "square.h"

class Player;

class Tuition : public Square {
public:
    void landOn(Player *player);
    Tuition();
};

#endif
