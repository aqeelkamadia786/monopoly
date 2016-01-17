#include "gym.h"
#include "building.h"
#include "player.h"
#include "game.h"
#include "dice.h"

using namespace std;

Gym::Gym(const string name) : Building(name) {
    die1 = Dice::getDie1();
    die2 = Dice::getDie2();
}

void Gym::buy(Player *player) {
    player->game->giveMoney(150, player);
    owner = player;
}

void Gym::landOn(Player *player) {
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
        } else if (owner->gyms() == 1) {
            int amount = 4 * (die1->value + die2->value);
            player->game->giveMoney(amount, player, owner);
        }   else {
            int amount = 10 * (die1->value + die2->value);
            player->game->giveMoney(amount, player, owner);
        }
        return;
    }
}

void Gym::Mortgage(bool answer) {
    if (answer == true && mortgaged == true) {
        cout << "This property is already mortgaged." << endl;
    }   else if (answer == false && mortgaged == false) {
        cout << "This property is not mortgaged." << endl;
    }   else if (answer == true && mortgaged == false) {
        cout << owner->name << " gained $75." << endl;
        owner->cash += 75;
        mortgaged = true;
    }   else {
        owner->game->giveMoney(90, owner);
        mortgaged = false;
    }
}

