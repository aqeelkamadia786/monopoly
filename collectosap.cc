#include "collectosap.h"
#include "player.h"
#include <iostream>


CollectOsap::CollectOsap() : Square("Collect OSAP") {}

using namespace std;

void CollectOsap::landOn(Player *player) {
    cout << player->name << " Landed on " << name << "." << endl;
    if (player->game->doubleOsap) {
        cout << "You get another $200 for landing on Collect Osap." << endl;
        player->cash += 200;
    }
}
