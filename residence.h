#ifndef __RESIDENCE__
#define __RESIDENCE__
#include "building.h"

class Player;

class Residence : public Building {
public:
    void buy(Player *player);
    void landOn(Player *player);
    void Mortgage(bool answer);
    Residence(const std::string name);
};

#endif

