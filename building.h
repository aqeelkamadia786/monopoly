#ifndef __BUILDING__
#define __BUILDING__
#include "square.h"
#include <string>

class Player;

class Building : public Square {
  public:
    Player *owner;
    bool mortgaged;
    int improvements;
    virtual void buy(Player *player)=0;
    virtual void Mortgage(bool answer)=0;
    virtual void landOn(Player *player)=0;
    
    Building(const std::string name);
    ~Building();
};

#endif

