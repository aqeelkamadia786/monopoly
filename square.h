#ifndef __SQUARE__
#define __SQUARE__
#include <string>

class Player;

class Square {
  public:
    //const std::string squareType;
    const std::string name;
    virtual void landOn(Player *player)=0;
    Square(const std::string name);
    virtual ~Square()=0;
};

#endif

