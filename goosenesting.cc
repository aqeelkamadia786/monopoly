#include "goosenesting.h"
#include "player.h"

GooseNesting::GooseNesting () : Square("Goose Nesting") {}

void GooseNesting::landOn(Player *player) {
    cout << player->name << " Landed on " << name << "." << endl;
    if (player->game->houseRules) {
        cout << player->name << " wins the jackpot of $" << player->game->bankMoney << "." << endl;
        player->cash += player->game->bankMoney;
        player->game->bankMoney = 0;
    }
}
