#include "residence.h"
#include "building.h"
#include "player.h"
#include "game.h"

using namespace std;

Residence::Residence (const string name) : Building(name) {}

void Residence::buy(Player *player) {
    player->game->giveMoney(200, player);
    owner = player;
}

void Residence::landOn(Player *player) {
    cout << player->name << " Landed on " << name << "." << endl;
    if (owner == NULL) {
        string str;
        cout << "Would you like to buy or auction?" << endl;
        cin >> str;
        if (str == "buy") {
            player->buy(this);
        } else {
            player->auction(this);
        }
    }   else if (owner == player) {
        return;
    }   else {
        if (mortgaged) {
            return;
        } else if (owner->residences() == 1) {
            player->game->giveMoney(25, player, owner);
        }   else if (owner->residences() == 2) {
            player->game->giveMoney(50, player, owner);
        }   else if (owner->residences() == 3) {
            player->game->giveMoney(100, player, owner);
        }   else {
            player->game->giveMoney(200, player, owner);
        }
    }
}

void Residence::Mortgage(bool answer) {
    if (answer == true && mortgaged == true) {
        cout << "This property is already mortgaged." << endl;
    }   else if (answer == false && mortgaged == false) {
        cout << "This property is not mortgaged." << endl;
    }   else if (answer == true && mortgaged == false) {
        cout << owner->name << " gained $100." << endl;
        owner->cash += 100;
        mortgaged = true;
    }   else {
        owner->game->giveMoney(120, owner);
        mortgaged = false;
    }
}
