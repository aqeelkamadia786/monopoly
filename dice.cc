#include "dice.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Dice *Dice::die1 = 0;
Dice *Dice::die2 = 0;

Dice *Dice::getDie1() {
    if (!die1) {
        die1 = new Dice;
    }
    return die1;
}

Dice *Dice::getDie2() {
    if (!die2) {
        die2 = new Dice;
    }
    return die2;
}

Dice::Dice(): value(0) {}

void Dice::roll(int d1, int d2) {
    if ((d1 == 0) && (d2 == 0)) {
        srand(time(NULL));
        int v1 = rand() % 6 + 1;
        die1->value = v1;
        int v2 = rand() % 6 + 1;
        die2->value = v2;
    }
    else {
        die1->value = d1;
        die2->value = d2;
    }
}



