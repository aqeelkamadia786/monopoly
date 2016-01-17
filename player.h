#ifndef __PLAYER__
#define __PLAYER__
#include <string>
#include <vector>
#include "building.h"
#include "academicbuilding.h"
#include "gym.h"
#include "residence.h"
#include "game.h"

class Player {
public:
    int cash;
    int location;
    int cups;
    bool inTimsLine;
    int turnsInTims;
    const char character;
    const std::string name;
    bool bankrupt;
    Game * game;
    int residences();
    int gyms();
    void Advance(int numSquaresAdvanced);
    void goBack(int numSquaresGoneBack);
    void declareBankruptcy(Player *debtor = 0);
    void tradeResponse(Player *sender, std::string give, std::string receive);
    void mortgage(Building *a, bool answer);
    void buy(Residence *res);
    void buy(AcademicBuilding *acad);
    void buy(Gym *gym);
    void skip();
    void improve(AcademicBuilding *a, bool answer);
    void displayAssets();
    void useCup();
    void auction(Building *building);
    
    Player();
    Player(Game * game, const char character, const std::string name, int numCups, int cash, int location);
};

#endif

