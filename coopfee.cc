#include "coopfee.h"
#include "player.h"

CoopFee::CoopFee () : Square("Coop Fee") {}

void CoopFee::landOn(Player *player) {
    cout << player->name << " Landed on " << name << " and must pay $150." << endl;
    player->game->giveMoney(150, player);
    if (player->game->houseRules) {
        player->game->bankMoney += 150;
    }
}
