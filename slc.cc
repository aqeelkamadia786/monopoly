#include "slc.h"
#include "player.h"
#include <cstdlib>

SLC::SLC() : Square("SLC") {}

void SLC::landOn(Player *player) {
    cout << player->name << " Landed on " << name << "." << endl;
    srand(time(NULL));
    int timsCupResult = rand() % 100 + 1;
    if ((timsCupResult == 1) && (player->game->totalTimsCups() < 4)) {
        player->cups++;
        cout << "You have received a winning Roll Up the Rim cup." << endl;
        return;
    }
    int result = rand() % 24 + 1;
    if (result <= 3) {
        cout << player->name << " goes back 3 spaces." << endl;
        player->goBack(3);
    } else if (result <= 7) {
        cout << player->name << " goes back 2 spaces." << endl;
        player->goBack(2);
    } else if (result <= 11) {
        cout << player->name << " goes back 1 space." << endl;
        player->goBack(1);
    } else if (result <= 14) {
        cout << player->name << " goes forward 1 space." << endl;
        player->Advance(1);
    } else if (result <= 18) {
        cout << player->name << " goes forward 2 spaces." << endl;
        player->Advance(2);
    } else if (result <= 22) {
        cout << player->name << " goes forward 3 spaces." << endl;
        player->Advance(3);
    } else if (result <= 23) {
        cout << player->name << " goes to Tims line." << endl;
        player->inTimsLine = true;
        if (player->location < 10) {
            player->Advance(10 - player->location);
        } else {
            player->goBack(player->location - 10);
        }
    } else {
        cout << player->name << " advances to collect OSAP." << endl;
        player->Advance(40 - player->location);
    }
}
