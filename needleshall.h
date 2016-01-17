#ifndef __NEEDLESHALL__
#define __NEEDLESHALL__
#include "square.h"

class Player;

class NeedlesHall : public Square {
public:    
    void landOn(Player *player);
    NeedlesHall();
};

#endif
