#include "tuition.h"
#include "player.h"
#include "academicbuilding.h"
#include <vector>

using namespace std;

Tuition::Tuition() : Square("Tuition") {
    
}

void Tuition::landOn(Player *player) {
    cout << player->name << " Landed on " << name << " and must pay $300 or 10% of their net worth." << endl;
    int netWorth = 0;
    netWorth += player->cash;
    netWorth += player->gyms() * 150;
    netWorth += player->residences() * 200;
    for (int i = 0; i < 22; i++) {
        if (player == player->game->academicBuildings[i]->owner) {
            netWorth += player->game->academicBuildings[i]->cost;
            netWorth += player->game->academicBuildings[i]->improvements * player->game->academicBuildings[i]->improvementCost;
        }
    }
    cout << "Enter 0 to choose to pay 10% of your net worth, enter 1 to pay $300." << endl;
    int result;
    cin >> result;
    if (!result) {
        player->game->giveMoney(.1 * netWorth, player);
        if (player->game->houseRules) {
            player->game->bankMoney += .1 * netWorth;
        }
    } else {
        player->game->giveMoney(300, player);
        if (player->game->houseRules) {
            player->game->bankMoney += 300;
        }
    }
}
