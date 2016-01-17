#ifndef __GAME__
#define __GAME__
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Square;
class Player;
class Building;
class AcademicBuilding;
class Gym;
class Residence;
class Dice;

class Game {
  public:
    Player ** players;
    int numPlayers;
    int turn;
    bool testing;
    bool houseRules;
    bool evenBuild;
    bool doubleOsap;
    int bankMoney;
    void play(bool testing, bool loadgame, ifstream *filename = 0);
    Square *board[40];
    Building *buildings[28];
    AcademicBuilding *academicBuildings[22];
    Gym *gyms[2];
    Residence *residences[4];
    Dice *die1;
    Dice *die2;
    void convertToFile(ofstream *outFile);
    void loadFromFile(ifstream *inFile);
    int checkPlayersRemaining();
    void auction(Building *building);
    void giveMoney(int amount, Player *playerIndebt, Player *debtor = 0);
    int totalTimsCups();
    bool getOutOfTims(Player *player);
    void printBoard();
    void displayOptions();
    bool monopoly(Player *player, string faculty);
    
    Game();
    ~Game();
};

#endif

