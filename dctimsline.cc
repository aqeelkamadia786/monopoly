#include <map>
#include <iostream>
#include "dctimsline.h"
#include "player.h"

using namespace std;

DCTimsLine::DCTimsLine() : Square("DC Tims Line") {}

void DCTimsLine::landOn(Player *player) {
    if (player->inTimsLine == true) {
        cout << "You are in the DC Tims Line" << endl;
        player->turnsInTims = 0;
    } else {
        cout << player->name << " is just visiting the " << name << "." << endl;
    }
}

