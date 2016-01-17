#include "gototims.h"
#include "player.h"

GoToTims::GoToTims() : Square("Go To Tims") {}

void GoToTims::landOn(Player *player) {
    cout << player->name << " must " << name << "." << endl;
    player->inTimsLine = true;
    player->goBack(20);
}
