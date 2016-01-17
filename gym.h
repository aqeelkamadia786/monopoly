#ifndef __GYM__
#define __GYM__
#include "building.h"
#include "dice.h"

class Player;

class Gym : public Building {
    Dice *die1;
    Dice *die2;
public:
    void buy(Player *player);
    void landOn(Player *player);
    void Mortgage(bool answer);
    Gym(const std::string name);
};

#endif
