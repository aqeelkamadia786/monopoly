#ifndef __COOPFEE__
#define __COOPFEE__
#include "square.h"

class Player;

class CoopFee : public Square {
public:
    void landOn(Player *player);
    CoopFee();
};

#endif

