#include "building.h"
#include <iostream>
#include "academicbuilding.h"
#include "player.h"

using namespace std;

AcademicBuilding::AcademicBuilding(const string name, const string faculty, const int cost, const int ic, const int tc0, const int tc1, const int tc2, const int tc3, const int tc4, const int tc5) : Building(name), faculty(faculty), cost(cost), improvementCost(ic), tuitionIndex{tc0, tc1, tc2, tc3, tc4, tc5} {}

AcademicBuilding::~AcademicBuilding() {}

void AcademicBuilding::buy(Player *player) {
    owner = player;
    player->game->giveMoney(cost, player);
}

void AcademicBuilding::addImprovement() {
    if (owner->game->evenBuild) {
        int newImprovement = improvements + 1;
        int min = newImprovement;
        int max = newImprovement;
        for (int i = 0; i < 22; i++) {
            if (owner->game->academicBuildings[i]->faculty == faculty) {
                if (owner->game->academicBuildings[i]->improvements < min) {
                    min = owner->game->academicBuildings[i]->improvements;
                }
                if (owner->game->academicBuildings[i]->improvements > max) {
                    max = owner->game->academicBuildings[i]->improvements;
                }
            }
        }
        if (max - min > 1) {
            cout << "You must have an even build, add improvements on another building in this faculty before this one." << endl;
            return;
        }
    }
    for (int i = 0; i < 22; i++) {
        if ((owner->game->academicBuildings[i]->faculty == faculty) && (owner->game->academicBuildings[i]->owner != owner)) {
            cout << "You must buy all the buildings in the faculty :" << faculty << endl;
            return;
        }
    }
    if (improvements < 5) {
        improvements++;
        owner->game->giveMoney(improvementCost, owner);
    }
}

void AcademicBuilding::removeImprovement() {
    if (owner->game->evenBuild) {
        int newImprovement = improvements - 1;
        int min = newImprovement;
        int max = newImprovement;
        for (int i = 0; i < 22; i++) {
            if (owner->game->academicBuildings[i]->faculty == faculty) {
                if (owner->game->academicBuildings[i]->improvements < min) {
                    min = owner->game->academicBuildings[i]->improvements;
                }
                if (owner->game->academicBuildings[i]->improvements > max) {
                    max = owner->game->academicBuildings[i]->improvements;
                }
            }
        }
        if (max - min > 1) {
            cout << "You must have an even build, remove improvements on another building in this faculty before this one." << endl;
            return;
        }
    }
    if (improvements > 0) {
        improvements--;
        owner->cash += improvementCost * .5;
        cout << owner->name << " gained $" << (improvementCost * .5) << "." << endl;
    }
}

void AcademicBuilding::landOn(Player *player) {
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
        } else if ((player->game->monopoly(owner, faculty)) && (improvements == 0)) {
            player->game->giveMoney(2 * tuitionIndex[improvements], player, owner);
            return;
        } else {
            player->game->giveMoney(tuitionIndex[improvements], player, owner);
            return;
        }
    }
}

void AcademicBuilding::Mortgage(bool answer) {
    if (answer == true && mortgaged == true) {
        cout << "This property is already mortgaged." << endl;
    }   else if (answer == false && mortgaged == false) {
        cout << "This property is not mortgaged." << endl;
    }   else if (answer == true && mortgaged == false) {
        owner->cash += .5 * cost;
        cout << owner->name << " gained $" << (.5 * cost) << "." << endl;
        mortgaged = true;
    }   else {
        owner->game->giveMoney(.6 * cost, owner);
        mortgaged = false;
    }
}

