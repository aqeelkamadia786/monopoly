#include "player.h"
#include "game.h"
#include "building.h"
#include "academicbuilding.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

const int numSquares = 40;
const int numBuildings = 28;
const int numResidences = 4;
const int numGyms = 2;
const int numAcademicBuildings = 22;

Player::Player(Game *game, const char character, const string name, int numCups, int cash, int location) : game(game), character(character), name(name), cups(numCups), cash(cash), location(location) {
    bankrupt = false;
    inTimsLine = false;
    turnsInTims = 0;
}


int Player::residences() {
    int myResidences = 0;
    for (int i = 0; i < numResidences; i++) {
        if (game->residences[i]->owner == this) {
            myResidences++;
        }
    }
    return myResidences;
}

int Player::gyms() {
    int myGyms = 0;
    for (int i = 0; i < numGyms; i++) {
        if (game->gyms[i]->owner == this) {
            myGyms++;
        }
    }
    return myGyms;
}

void Player::Advance(int numSquaresAdvanced) {
    location += numSquaresAdvanced;
    if (location >= numSquares) {
        location -= numSquares;
        cout << name << " gained $200 for collecting OSAP." << endl;
        cash += 200;
    }
    game->printBoard();
    game->board[location]->landOn(this);
}

void Player::goBack(int numSquaresGoneBack) {
    location -= numSquaresGoneBack;
    if (location < 0) {
        location += numSquares;
    }
    if (location >= numSquares) {
        location -= numSquares;
    }
    game->printBoard();
    game->board[location]->landOn(this);
}

void Player::declareBankruptcy(Player *debtor) {
    bankrupt = true;
    cout << name << " has declared bankruptcy and is eliminated." << endl;
    cups = 0;
    
    int sum = 0;
    for (int i = 0; i < game->numPlayers; i++) {
        if (!game->players[i]->bankrupt) {
            sum++;
        }
    }
    if (sum == 1) {
        return;
    }
    
    if (debtor == NULL) {
        cout << "All of their properties are being auctioned off." << endl;
        for (int i = 0; i < numBuildings; i++) {
            if (game->buildings[i]->owner == this) {
                game->auction(game->buildings[i]);
            }
        }
    } else {
        cout << "All of their properties go to " << debtor->name << endl;
        for (int i = 0; i < numBuildings; i++) {
            if (game->buildings[i]->owner == this) {
                game->buildings[i]->owner = debtor;
                if (game->buildings[i]->mortgaged) {
                    for (int p = 0; p < numAcademicBuildings; p++) {
                        if (game->academicBuildings[p] == game->buildings[i]) {
                            game->giveMoney(.05 * game->academicBuildings[p]->cost, debtor);
                        }
                    }
                    for (int p = 0; p < numResidences; p++) {
                        if (game->residences[p] == game->buildings[i]) {
                            game->giveMoney(.1 * 75, debtor);
                        }
                    }
                    for (int p = 0; p < numGyms; p++) {
                        if (game->gyms[p] == game->buildings[i]) {
                            game->giveMoney(.1 * 100, debtor);
                        }
                    }
                    
                }
            }
        }
    }
}

void Player::tradeResponse(Player *sender, string give, string receive) {
    cout << name << ", do you accept to trade " << give << " for " << receive << "? (y/n)" << endl;
    char response;
    cin >> response;
    if (response != 'y') {
        return;
    }
    
    Building *giveBuilding = 0;
    for (int p = 0; p < numBuildings; p++) {
        if (game->buildings[p]->name == give) {
            giveBuilding = game->buildings[p];
            if (giveBuilding->owner != this) {
                cout << "You can only trade what is yours." << endl;
                return;
            }
        }
    }
    
    
    Building *receiveBuilding = 0;
    for (int p = 0; p < numBuildings; p++) {
        if (game->buildings[p]->name == receive) {
            receiveBuilding = game->buildings[p];
            if (receiveBuilding->owner != sender) {
                cout << "You can only trade what is yours." << endl;
                return;
            }
        }
    }
    
    
    AcademicBuilding *giveAcad = 0;
    for (int p = 0; p < numAcademicBuildings; p++) {
        if (game->academicBuildings[p]->name == give) {
            giveAcad = game->academicBuildings[p];
            
        }
    }
    if (giveAcad) {
        string fac = giveAcad->faculty;
        if (game->monopoly(giveAcad->owner, fac)) {
            for (int q = 0; q < numAcademicBuildings; q++) {
                if ((game->academicBuildings[q]->faculty == fac) &&
                    (game->academicBuildings[q]->improvements > 0)) {
                    cout << "Cannot trade a property with buildings in the same faculty with improvements." << endl;
                    return;
                }
            }
        }
    }
    
    AcademicBuilding *receiveAcad = 0;
    for (int p = 0; p < numAcademicBuildings; p++) {
        if (game->academicBuildings[p]->name == receive) {
            receiveAcad = game->academicBuildings[p];
            
        }
    }
    if (receiveAcad) {
        string fac = receiveAcad->faculty;
        if (game->monopoly(receiveAcad->owner, fac)) {
            for (int q = 0; q < numAcademicBuildings; q++) {
                if ((game->academicBuildings[q]->faculty == fac) &&
                    (game->academicBuildings[q]->improvements > 0)) {
                    cout << "Cannot trade a property with buildings in the same faculty with improvements." << endl;
                    return;
                }
            }
        }
    }
    
    
    int giveInt = -1;
    int receiveInt = -1;
    if (((give[give.length() - 1] >= '0') && (give[give.length() - 1] <= '9')) &&
        ((receive[receive.length() - 1] >= '0') && (receive[receive.length() - 1] <= '9'))) {
        
        istringstream gss(give);
        gss >> giveInt;
        
        istringstream rss(receive);
        rss >> receiveInt;
        
        if (giveInt > receiveInt) {
            game->giveMoney(giveInt - receiveInt, this, sender);
        } else {
            game->giveMoney(receiveInt - giveInt, sender, this);
        }
        
    } else if ((give[give.length() - 1] >= '0') && (give[give.length() - 1] <= '9')) {
        
        istringstream gss(give);
        gss >> giveInt;
        
        game->giveMoney(giveInt, this, sender);
        
        receiveBuilding->owner = this;
        
    } else if ((receive[receive.length() - 1] >= '0') && (receive[receive.length() - 1] <= '9')) {
        istringstream rss(receive);
        rss >> receiveInt;
        
        game->giveMoney(receiveInt, sender, this);
        
        giveBuilding->owner = sender;
    } else {
        receiveBuilding->owner = this;
        giveBuilding->owner = sender;
    }
}

void Player::mortgage(Building *a, bool answer) {
    a->Mortgage(answer);
}

void Player::buy(Residence *res) {
    res->buy(this);
}

void Player::buy(AcademicBuilding *acad) {
    acad->buy(this);
}

void Player::buy(Gym *gym) {
    gym->buy(this);
}

void Player::skip() {
    // skips turn
}

void Player::improve(AcademicBuilding *a, bool answer) {
    if (answer == true) {
        a->addImprovement();
    }   else {
        a->removeImprovement();
    }
}

void Player::displayAssets() {
    cout << "Cash: $" << cash << endl;
    for (int i = 0; i < numBuildings; i++) {
        if (game->buildings[i]->owner == this) {
            cout << game->buildings[i]->name << " (" << game->buildings[i]->improvements << " improvements)" << endl;
        }
    }
}

void Player::useCup() {
    cups--;
}

void Player::auction(Building *building) {
    game->auction(building);
}


