#ifndef __DCTIMSLINE__
#define __DCTIMSLINE__
#include "square.h"
#include "dice.h"
#include <map>

class Player;

class DCTimsLine : public Square {
public:
    void landOn(Player *player);
    DCTimsLine();
};

#endif

