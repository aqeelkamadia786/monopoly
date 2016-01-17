#include "needleshall.h"
#include "player.h"
#include <cstdlib>

using namespace std;

NeedlesHall::NeedlesHall() : Square("Needles Hall") {}

void NeedlesHall::landOn(Player *player) {
    cout << player->name << " Landed on " << name << "." << endl;
    srand(time(NULL));
    int timsCupResult = rand() % 100 + 1;
    if ((timsCupResult == 1) && (player->game->totalTimsCups() < 4)) {
        player->cups++;
        cout << "You have received a winning Roll Up the Rim cup." << endl;
        return;
    }
    int result = rand() % 18 + 1;
    if (result == 1) {
        player->game->giveMoney(200, player);
    } else if (result <= 3) {
        player->game->giveMoney(100, player);
    } else if (result <= 6) {
        player->game->giveMoney(50, player);
    } else if (result <= 12) {
        cout << player->name << " gained $25." << endl;
        player->cash += 25;
    } else if (result <= 15) {
        cout << player->name << " gained $50." << endl;
        player->cash += 50;
    } else if (result <= 17) {
        cout << player->name << " gained $100." << endl;
        player->cash += 100;
    } else {
        cout << player->name << " gained $200." << endl;
        player->cash += 200;
    }
}
