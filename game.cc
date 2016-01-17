#include "game.h"
#include "player.h"
#include "square.h"
#include "collectosap.h"
#include "slc.h"
#include "academicbuilding.h"
#include "gym.h"
#include "tuition.h"
#include "residence.h"
#include "dctimsline.h"
#include "needleshall.h"
#include "coopfee.h"
#include "goosenesting.h"
#include <vector>
#include <ostream>
#include <sstream>
#include <string>
#include <fstream>
#include "gototims.h"

using namespace std;

const int numSquares = 40;
const int numBuildings = 28;
const int numAcademicBuildings = 22;
const int numGyms = 2;
const int numResidences = 4;

Game::Game() {
    houseRules = false;
    evenBuild = false;
    doubleOsap = false;
    bankMoney = 0;
    testing = false;
    board[0] = new CollectOsap;
    AcademicBuilding *b1 = new AcademicBuilding("AL", "Arts1", 40, 50, 2, 10, 30, 90, 160, 250);
    buildings[0] = b1;
    academicBuildings[0] = b1;
    board[1] = b1;
    board[2] = new SLC;
    AcademicBuilding *b3 = new AcademicBuilding("ML", "Arts1", 60, 50, 4, 20, 60, 180, 320, 450);
    buildings[1] = b3;
    academicBuildings[1] = b3;
    board[3] = b3;
    board[4] = new Tuition;
    Residence *b5 = new Residence("MKV");
    buildings[2] = b5;
    residences[0] = b5;
    board[5] = b5;
    AcademicBuilding *b6 = new AcademicBuilding("ECH", "Arts2", 100, 50, 6, 30, 90, 270, 400, 550);
    buildings[3] = b6;
    academicBuildings[2] = b6;
    board[6] = b6;
    board[7] = new NeedlesHall;
    AcademicBuilding *b8 = new AcademicBuilding("PAS", "Arts2", 100, 50, 6, 30, 90, 270, 400, 550);
    buildings[4] = b8;
    academicBuildings[3] = b8;
    board[8] = b8;
    AcademicBuilding *b9 = new AcademicBuilding("HH", "Arts2", 120, 50, 8, 40, 100, 300, 450, 600);
    buildings[5] = b9;
    academicBuildings[4] = b9;
    board[9] = b9;
    board[10] = new DCTimsLine;
    AcademicBuilding *b11 = new AcademicBuilding("RCH", "Eng", 140, 100, 10, 50, 150, 450, 625, 750);
    buildings[6] = b11;
    academicBuildings[5] = b11;
    board[11] = b11;
    Gym *b12 = new Gym("PAC");
    buildings[7] = b12;
    gyms[0] = b12;
    board[12] = b12;
    AcademicBuilding *b13 = new AcademicBuilding("DWE", "Eng", 140, 100, 10, 50, 150, 450, 625, 750);
    buildings[8] = b13;
    academicBuildings[6] = b13;
    board[13] = b13;
    AcademicBuilding *b14 = new AcademicBuilding("CPH", "Eng", 160, 100, 12, 60, 180, 500, 700, 900);
    buildings[9] = b14;
    academicBuildings[7] = b14;
    board[14] = b14;
    Residence *b15 = new Residence("UWP");
    buildings[10] = b15;
    residences[1] = b15;
    board[15] = b15;
    AcademicBuilding *b16 = new AcademicBuilding("LHI", "Health", 180, 100, 14, 70, 200, 550, 750, 950);
    buildings[11] = b16;
    academicBuildings[8] = b16;
    board[16] = b16;
    board[17] = new SLC;
    AcademicBuilding *b18 = new AcademicBuilding("BMH", "Health", 180, 100, 14, 70, 200, 550, 750, 950);
    buildings[12] = b18;
    academicBuildings[9] = b18;
    board[18] = b18;
    AcademicBuilding *b19 = new AcademicBuilding("OPT", "Health", 200, 100, 16, 80, 220, 600, 800, 1000);
    buildings[13] = b19;
    academicBuildings[10] = b19;
    board[19] = b19;
    board[20] = new GooseNesting;
    AcademicBuilding *b21 = new AcademicBuilding("EV1", "Env", 220, 150, 18, 90, 250, 700, 875, 1050);
    buildings[14] = b21;
    academicBuildings[11] = b21;
    board[21] = b21;
    board[22] = new NeedlesHall;
    AcademicBuilding *b23 = new AcademicBuilding("EV2", "Env", 220, 150, 18, 90, 250, 700, 875, 1050);
    buildings[15] = b23;
    academicBuildings[12] = b23;
    board[23] = b23;
    AcademicBuilding *b24 = new AcademicBuilding("EV3", "Env", 240, 150, 20, 100, 300, 750, 925, 1100);
    buildings[16] = b24;
    academicBuildings[13] = b24;
    board[24] = b24;
    Residence *b25 = new Residence("V1");
    buildings[17] = b25;
    residences[2] = b25;
    board[25] = b25;
    AcademicBuilding *b26 = new AcademicBuilding("PHYS", "Sci1", 260, 150, 22, 110, 330, 800, 975, 1150);
    buildings[18] = b26;
    academicBuildings[14] = b26;
    board[26] = b26;
    AcademicBuilding *b27 = new AcademicBuilding("B1", "Sci1", 260, 150, 22, 110, 330, 800, 975, 1150);
    buildings[19] = b27;
    academicBuildings[15] = b27;
    board[27] = b27;
    Gym *b28 = new Gym("CIF");
    buildings[20] = b28;
    gyms[1] = b28;
    board[28] = b28;
    AcademicBuilding *b29 = new AcademicBuilding("B2", "Sci1", 280, 150, 24, 120, 360, 850, 1025, 1200);
    buildings[21] = b29;
    academicBuildings[16] = b29;
    board[29] = b29;
    board[30] = new GoToTims;
    AcademicBuilding *b31 = new AcademicBuilding("EIT", "Sci2", 300, 200, 26, 130, 390, 900, 1100, 1275);
    buildings[22] = b31;
    academicBuildings[17] = b31;
    board[31] = b31;
    AcademicBuilding *b32 = new AcademicBuilding("ESC", "Sci2", 300, 200, 26, 130, 390, 900, 1100, 1275);
    buildings[23] = b32;
    academicBuildings[18] = b32;
    board[32] = b32;
    board[33] = new SLC;
    AcademicBuilding *b34 = new AcademicBuilding("C2", "Sci2", 320, 200, 28, 150, 450, 1000, 1200, 1400);
    buildings[24] = b34;
    academicBuildings[19] = b34;
    board[34] = b34;
    Residence *b35 = new Residence("REV");
    buildings[25] = b35;
    residences[3] = b35;
    board[35] = b35;
    board[36] = new NeedlesHall;
    AcademicBuilding *b37 = new AcademicBuilding("MC", "Math", 350, 200, 35, 175, 500, 1100, 1300, 1500);
    buildings[26] = b37;
    academicBuildings[20] = b37;
    board[37] = b37;
    board[38] = new CoopFee;
    AcademicBuilding *b39 = new AcademicBuilding("DC", "Math", 400, 200, 50, 200, 600, 1400, 1700, 2000);
    buildings[27] = b39;
    academicBuildings[21] = b39;
    board[39] = b39;
    
}

void Game::play(bool test, bool loadgame, ifstream *inFile) {
    //game->play(testing, loadgame);
    //map<int, Player *> players;
    testing = test;
    
    die1 = Dice::getDie1();
    die2 = Dice::getDie2();
    
    cout << "How many players?" << endl;
    
    
    
    if (loadgame) {
        loadFromFile(inFile);
        
    } else {
        cin >> numPlayers;
        players = new Player *[numPlayers];
        cout << "G: Goose" << endl;
        cout << "B: GRT Bus" << endl;
        cout << "D: Tim Hortons Doughnut" << endl;
        cout << "P: Professor" << endl;
        cout << "S: Student" << endl;
        cout << "$: Money" << endl;
        cout << "L: Laptop" << endl;
        cout << "T: Pink tie" << endl;
        for (int i = 0; i < numPlayers; i++) {
            string name;
            char character;
            cout << "Player " << i << ", Enter your name." << endl;
            cin >> name;
            
            cout << "Player " << i << ", Enter your preferred character." << endl;
            cin >> character;
            
            players[i] = new Player(this, character, name, 0, 1500, 0);
        }
    }
    
    cout << "Would you like to play with the Goose Nesting Jackpot? (y/n)" << endl;
    string response;
    cin >> response;
    if (response == "y") {
        houseRules = true;
    } else {
        houseRules = false;
    }
    cout << "Would you like double OSAP money if you land on Collect OSAP? (y/n)" << endl;
    cin >> response;
    if (response == "y") {
        doubleOsap = true;
    } else {
        doubleOsap = false;
    }
    cout << "Would you like to play with the Even Build Rule? (y/n)" << endl;
    cin >> response;
    if (response == "y") {
        evenBuild = true;
    } else {
        evenBuild = false;
    }
    
    printBoard();
    
    int doubleTimes = 0;
    bool doubles = false;
    while (true) {
        for (int i = 0; i < numPlayers; i++) {
            bool rolled = false;
            if (players[i]->bankrupt) {
                continue;
            }
            if (checkPlayersRemaining() < 2) {
                return;
            }
            
            while (true) {
                if (players[i]->bankrupt) {
                    break;
                }
                if (checkPlayersRemaining() < 2) {
                    return;
                }
                
                string c;
                if (rolled) {
                    cout << players[i]->name << " may make some final transactions or enter 'next'." << endl;
                } else {
                    cout << players[i]->name << "'s turn..." << endl;
                }
                cin.clear();
                cin >> c;
                
                if (c == "roll") {
                    if (!rolled) {
                        if (testing) {
                            // cout << "enter dice values" << endl;
                            string line;
                            int d1 = 0;
                            int d2 = 0;
                            getline(cin, line);
                            stringstream ss(line);
                            ss >> d1;
                            ss >> d2;
                            Dice::roll(d1, d2);
                        } else {
                            Dice::roll();
                        }
                        if (die1->value == die2->value) {
                            doubles = true;
                        } else {
                            doubles = false;
                        }
                        if (!players[i]->inTimsLine) {
                            cout << players[i]->name << " rolled a " << die1->value << " and a " << die2->value << "." << endl;
                        }
                        if (players[i]->inTimsLine) {
                            if (doubles) {
                                players[i]->inTimsLine = false;
                            } else {
                                int breakOut = getOutOfTims(players[i]);
                                if (breakOut) {
                                    doubles = false;
                                } else {
                                    break;
                                }
                            }
                        }
                        
                        if (doubles) {
                            doubleTimes++;
                        } else {
                            doubleTimes = 0;
                        }
                        if (doubleTimes == 3) {
                            cout << "You rolled doubles 3 times in a row." << endl;
                            players[i]->inTimsLine = true;
                            players[i]->turnsInTims = 0;
                            doubleTimes = 0;
                            doubles = false;
                            players[i]->goBack(players[i]->location - 10);
                        } else {
                            players[i]->Advance(die1->value + die2->value);
                        }
                        rolled = true;
                        if (doubles) {
                            break;
                        }
                    } else {
                        cout << "You already rolled, you may still make trascations or enter 'next' to end your turn." << endl;
                    }
                    //break;
                } else if (c == "improve") {
                    string prop;
                    cin >> prop;
                    string buySell;
                    cin >> buySell;
                    for (int p = 0; p < numAcademicBuildings; p++) {
                        if ((academicBuildings[p]->name == prop) && (academicBuildings[p]->owner == players[i])) {
                            if (buySell == "buy") {
                                players[i]->improve(academicBuildings[p], true);
                            } else {
                                players[i]->improve(academicBuildings[p], false);
                            }
                        }
                    }
                } else if (c == "mortgage") {
                    string prop;
                    cin >> prop;
                    for (int p = 0; p < numAcademicBuildings; p++) {
                        if ((academicBuildings[p]->name == prop) && (academicBuildings[p]->owner == players[i])) {
                            players[i]->mortgage(academicBuildings[p], true);
                        }
                    }
                    for (int p = 0; p < numResidences; p++) {
                        if ((residences[p]->name == prop) && (residences[p]->owner == players[i])) {
                            players[i]->mortgage(residences[p], true);
                        }
                    }
                    for (int p = 0; p < numGyms; p++) {
                        if ((gyms[p]->name == prop) && (gyms[p]->owner == players[i])) {
                            players[i]->mortgage(gyms[p], true);
                        }
                    }
                } else if (c == "unmortgage") {
                    string prop;
                    cin >> prop;
                    for (int p = 0; p < numAcademicBuildings; p++) {
                        if ((academicBuildings[p]->name == prop) && (academicBuildings[p]->owner == players[i])) {
                            players[i]->mortgage(academicBuildings[p], false);
                        }
                    }
                    for (int p = 0; p < numResidences; p++) {
                        if ((residences[p]->name == prop) && (residences[p]->owner == players[i])) {
                            players[i]->mortgage(residences[p], false);
                        }
                    }
                    for (int p = 0; p < numGyms; p++) {
                        if ((gyms[p]->name == prop) && (gyms[p]->owner == players[i])) {
                            players[i]->mortgage(gyms[p], false);
                        }
                    }
                } else if (c == "assets") {
                    players[i]->displayAssets();
                } else if (c == "trade") {
                    string name;
                    cin >> name;
                    string give;
                    cin >> give;
                    string receive;
                    cin >> receive;
                    for (int j = 0; j < numPlayers; j++) {
                        if (players[j]->name == name) {
                            players[j]->tradeResponse(players[i], receive, give);
                            break;
                        }
                    }
                } else if (c == "bankrupt") {
                    players[i]->declareBankruptcy();
                    if (checkPlayersRemaining() < 2) {
                        return;
                    }
                    break;
                } else if (c == "save") {
                    string filename;
                    cin >> filename;
                    ofstream *outFile = new ofstream( filename.c_str() );
                    convertToFile(outFile);
                    delete outFile;
                } else if (c == "next") {
                    if (rolled) {
                        break;
                    } else {
                        cout << "You must roll first." << endl;
                    }
                } else if (c == "options") {
                    displayOptions();
                } else if (c == "quit") {
                    return;
                }
            }
            if (doubles) {
                i--;
            }
        }
    }
}

void Game::giveMoney(int amount, Player *playerIndebt, Player *debtor) {
    playerIndebt->cash -= amount;
    
    if (debtor) {
        debtor->cash += amount;
        cout << playerIndebt->name << " pays " << debtor->name << " $" << amount << endl;
    } else {
        cout << playerIndebt->name << " pays $" << amount << endl;
    }
    
    if (playerIndebt->cash < 0) {
        cout << playerIndebt->name << " must either declare bankruptcy or make transactions to repay their debt." << endl;
    }
    while (playerIndebt->cash < 0) {
        string c;
        cin >> c;
        if (c == "improve") {
            string prop;
            cin >> prop;
            string buySell;
            cin >> buySell;
            for (int p = 0; p < numAcademicBuildings; p++) {
                if ((academicBuildings[p]->name == prop) && (academicBuildings[p]->owner == playerIndebt)) {
                    if (buySell == "buy") {
                        playerIndebt->improve(academicBuildings[p], true);
                    } else {
                        playerIndebt->improve(academicBuildings[p], false);
                    }
                }
            }
        } else if (c == "mortgage") {
            string prop;
            cin >> prop;
            for (int p = 0; p < numAcademicBuildings; p++) {
                if ((academicBuildings[p]->name == prop) && (academicBuildings[p]->owner == playerIndebt)) {
                    playerIndebt->mortgage(academicBuildings[p], true);
                }
            }
            for (int p = 0; p < numResidences; p++) {
                if ((residences[p]->name == prop) && (residences[p]->owner == playerIndebt)) {
                    playerIndebt->mortgage(residences[p], true);
                }
            }
            for (int p = 0; p < numGyms; p++) {
                if ((gyms[p]->name == prop) && (gyms[p]->owner == playerIndebt)) {
                    playerIndebt->mortgage(gyms[p], true);
                }
            }
        } else if (c == "unmortgage") {
            string prop;
            cin >> prop;
            for (int p = 0; p < numAcademicBuildings; p++) {
                if ((academicBuildings[p]->name == prop) && (academicBuildings[p]->owner == playerIndebt)) {
                    playerIndebt->mortgage(academicBuildings[p], false);
                }
            }
            for (int p = 0; p < numResidences; p++) {
                if ((residences[p]->name == prop) && (residences[p]->owner == playerIndebt)) {
                    playerIndebt->mortgage(residences[p], false);
                }
            }
            for (int p = 0; p < numGyms; p++) {
                if ((gyms[p]->name == prop) && (gyms[p]->owner == playerIndebt)) {
                    playerIndebt->mortgage(gyms[p], false);
                }
            }
        } else if (c == "assets") {
            playerIndebt->displayAssets();
        } else if (c == "trade") {
            string name;
            cin >> name;
            string give;
            cin >> give;
            string receive;
            cin >> receive;
            for (int j = 0; j < numPlayers; j++) {
                if (players[j]->name == name) {
                    players[j]->tradeResponse(playerIndebt, receive, give);
                    break;
                }
            }
        } else if (c == "bankrupt") {
            playerIndebt->declareBankruptcy(debtor);
            break;
        } else if (c == "save") {
            string filename;
            cin >> filename;
            ofstream *outFile = new ofstream( filename.c_str() );
            convertToFile(outFile);
            delete outFile;
        } else if (c == "options") {
            displayOptions();
        }
    }
}

void Game::auction(Building *building) {
    cout << building->name << " is being auctioned." << endl;
    int passCount = numPlayers;
    int passed[numPlayers];
    int bid = 0;
    for (int i = 0; i < numPlayers; i++) {
        if (players[i]->bankrupt) {
            passed[i] = true;
            passCount--;
        } else {
            passed[i] = false;
        }
    }
    
    while (true) {
        for (int i = 0; i < numPlayers; i++) {
            if (passed[i]) {
                continue;
            }
            cout << players[i]->name << " can either enter \"pass\" or enter a number over $" << bid << " to bid." << endl;
            int myBid;
            cin >> myBid;
            if (cin.fail() || (bid >= myBid)) {
                cout << players[i]->name << " passed." << endl;
                passed[i] = true;
                passCount--;
                if (cin.fail()) {
                    cin.ignore();
                    cin.clear();
                    string rest;
                    cin >> rest;
                }
            } else {
                bid = myBid;
                cout << players[i]->name << " raised the bid to $" << bid << "." << endl;
            }
            if (passCount <= 1) {
                break;
            }
        }
        if (passCount <= 1) {
            break;
        }
    }
    
    for (int i = 0; i < numPlayers; i++) {
        if (passed[i] == false) {
            cout << players[i]->name << " won the property." << endl;
            building->owner = players[i];
            giveMoney(bid, players[i]);
        }
    }
    
    
}

void Game::convertToFile(ofstream *outFile) {
    *outFile << numPlayers << endl;
    for (int i = 0; i < numPlayers; i++) {
        *outFile << players[i]->name << " " << players[i]->character << " " << players[i]->cups << " " << players[i]->cash << " " << players[i]->location;
        if (players[i]->location == 10) {
            int inTims = players[i]->inTimsLine;
            *outFile << " " << inTims;
            if (inTims) {
                *outFile << " " << players[i]->turnsInTims;
            }
        }
        *outFile << endl;
    }
    for (int i = 0; i < numBuildings; i++) {
        *outFile << buildings[i]->name;
        if (!buildings[i]->owner) {
            *outFile << " BANK 0";
        } else if (buildings[i]->mortgaged) {
            *outFile << " " << buildings[i]->owner->name << " -1";
        } else {
            *outFile << " " << buildings[i]->owner->name << " " << buildings[i]->improvements;
        }
        *outFile << endl;
    }
}

void Game::loadFromFile(ifstream *inFile) {
    *inFile >> numPlayers;
    players = new Player *[numPlayers];
    map<string, Player *> nameMap;
    nameMap["BANK"] = NULL;
    for (int i = 0; i < numPlayers; i++) {
        string name;
        char c;
        int timsCups, cash, location;
        *inFile >> name >> c >> timsCups >> cash >> location;
        players[i] = new Player(this, c, name, timsCups, cash, location);
        nameMap[name] = players[i];
        if (location == 10) {
            int inTims;
            *inFile >> inTims;
            players[i]->inTimsLine = inTims;
            if (inTims > 0) {
                int turns;
                *inFile >> turns;
                players[i]->turnsInTims = turns;
            }
        }
    }
    for (int i = 0; i < numBuildings; i++) {
        string name, owner;
        int improvements;
        *inFile >> name >> owner >> improvements;
        buildings[i]->owner = nameMap[owner];
        if (improvements == -1) {
            buildings[i]->improvements = 0;
            buildings[i]->mortgaged = true;
        } else {
            buildings[i]->improvements = improvements;
        }
    }
}

bool Game::getOutOfTims(Player *player) {
    char response;
    if (player->cups) {
        cout << "Use a Roll up the Rim Cup? (y/n)" << endl;
        cin >> response;
        if (response == 'y') {
            player->useCup();
            player->inTimsLine = false;
            player->turnsInTims = 0;
            return true;
        }
    }
    if (player->turnsInTims < 2) {
        cout << "Pay to get out? (y/n)" << endl;
        cin >> response;
        if (response == 'y') {
            player->inTimsLine = false;
            player->turnsInTims = 0;
            if (houseRules) {
                bankMoney += 50;
            }
            giveMoney(50, player);
            return true;
        }
    } else {
        cout << "You must pay now!" << endl;
        giveMoney(50, player);
        player->inTimsLine = false;
        player->turnsInTims = 0;
        return true;
    }
    player->turnsInTims++;
    return false;
}

int Game::totalTimsCups() {
    int totalCups = 0;
    for (int i = 0; i < numPlayers; i++) {
        totalCups += players[i]->cups;
    }
    return totalCups;
}

int Game::checkPlayersRemaining() {
    int sum = 0;
    Player *onlyOne = 0;
    for (int i = 0; i < numPlayers; i++) {
        if (!players[i]->bankrupt) {
            onlyOne = players[i];
            sum++;
        }
    }
    if (sum == 1) {
        cout << onlyOne->name << " wins!!!" << endl;
    }
    return sum;
}

void Game::displayOptions() {
    cout << "Command Options:" << endl;
    cout << "'roll': roll the dice to advance" << endl;
    cout << "'trade' <player> <give> <receive>: offer a trade and give/receive cash or a building" << endl;
    cout << "'improve' <building> <buy/sell>: add or remove improvements to a building you own" << endl;
    cout << "'mortgage': mortgage one of your properties to gain cash" << endl;
    cout << "'unmortgage': mortgage one of your properties but lose cash" << endl;
    cout << "'save' <filename>: save the game to a file" << endl;
    cout << "'bankrupt': declare bankruptcy to be eliminated from the game" << endl;
    cout << "'next': once you have rolled, you may move onto the next player" << endl;
    cout << "'assets': display assets" << endl;
    cout << "'quit': quit game completely" << endl;
    cout << "'options': display options" << endl;
}

bool Game::monopoly(Player *player, string faculty) {
    for (int i = 0; i < numAcademicBuildings; i++) {
        if ((academicBuildings[i]->owner != player) && (academicBuildings[i]->faculty == faculty)) {
            return false;
        }
    }
    return true;
}

void Game::printBoard () {
    string im[numAcademicBuildings];
    string pl1[numSquares];
    string pl2[numSquares];
    
    for (int i = 0; i < numAcademicBuildings; i++) {
        im[i] = "       ";
    }
    for (int i = 0; i < numSquares; i++) {
        pl1[i] = "  ";
        pl2[i] = "      ";
    }
    char c1[2] = {'G','B'};
    char c2[6] = {'D','P','S','$','L','T'};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < numPlayers; j++) {
            if ((players[j]->character == c1[i]) && (!players[j]->bankrupt)) {
                pl1[players[j]->location][i] = c1[i];
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < numPlayers; j++) {
            if ((players[j]->character == c2[i]) && (!players[j]->bankrupt)) {
                pl2[players[j]->location][i] = c2[i];
            }
        }
    }
    for (int i = 0; i < numAcademicBuildings; i++) {
        if (academicBuildings[i]->owner) {
            im[i][0] = academicBuildings[i]->owner->character;
        }
        if (academicBuildings[i]->improvements >= 1) {
            im[i][2] = 'I';
        }
        if (academicBuildings[i]->improvements >= 2) {
            im[i][3] = 'I';
        }
        if (academicBuildings[i]->improvements >= 3) {
            im[i][4] = 'I';
        }
        if (academicBuildings[i]->improvements >= 4) {
            im[i][5] = 'I';
        }
        if (academicBuildings[i]->improvements >= 5) {
            im[i][6] = 'I';
        }
    }
    
    
    cout << "_________________________________________________________________________________________" << endl;
    cout << "|Goose  |" << im[11] << "|Needles|" << im[12] << "|" << im[13] << "|V1     |" << im[14] << "|" << im[15] << "|CIF    |" << im[16] << "|GO TO  |" << endl;
    cout << "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |" << endl;
    cout << "|     " << pl1[20] << "|EV1  " << pl1[21] << "|     " << pl1[22] << "|EV2  " << pl1[23] << "|EV3  " << pl1[24] << "|     " << pl1[25] << "|PHYS " << pl1[26] << "|B1   " << pl1[27] << "|     " << pl1[28] << "|B2   " << pl1[29] << "|     " << pl1[30] << "|" << endl;
    cout << "| " << pl2[20] << "| " << pl2[21] << "| " << pl2[22] << "| " << pl2[23] << "| " << pl2[24] << "| " << pl2[25] << "| " << pl2[26] << "| " << pl2[27] << "| " << pl2[28] << "| " << pl2[29] << "| " << pl2[30] << "|" << endl;
    cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" << endl;
    cout << "|" << im[10] << "|                                                                       |" << im[17] << "|" << endl;
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|OPT  " << pl1[19] << "|                                                                       |EIT  " << pl1[31] << "|" << endl;
    cout << "| " << pl2[19] << "|                                                                       | " << pl2[31] << "|" << endl;
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|" << im[9] << "|                                                                       |" << im[18] << "|" << endl;
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|BMH  " << pl1[18] << "|                                                                       |ESC  " << pl1[32] << "|" << endl;
    cout << "| " << pl2[18] << "|                                                                       | " << pl2[32] << "|" << endl;
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|SLC    |                                                                       |SLC    |" << endl;
    cout << "|       |                                                                       |       |" << endl;
    cout << "|     " << pl1[17] << "|                                                                       |     " << pl1[33] << "|" << endl;
    cout << "| " << pl2[17] << "|                                                                       | " << pl2[33] << "|" << endl;
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|" << im[8] << "|                                                                       |" << im[19] << "|" << endl;
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|LHI  " << pl1[16] << "|                                                                       |C2   " << pl1[34] << "|" << endl;
    cout << "| " << pl2[16] << "|                                                                       | " << pl2[34] << "|" << endl;
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|UWP    |                                                                       |REV    |" << endl;
    cout << "|       |                                                                       |       |" << endl;
    cout << "|     " << pl1[15] << "|                                                                       |     " << pl1[35] << "|" << endl;
    cout << "| " << pl2[15] << "|                                                                       | " << pl2[35] << "|" << endl;
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|" << im[7] << "|                                                                       |NEEDLES|" << endl;
    cout << "|-------|                                                                       |HALL   |" << endl;
    cout << "|CPH  " << pl1[14] << "|                                                                       |     " << pl1[36] << "|" << endl;
    cout << "| " << pl2[14] << "|                                                                       | " << pl2[36] << "|" << endl;
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|" << im[6] << "|                                                                       |" << im[20] << "|" << endl;
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|DWE  " << pl1[13] << "|                                                                       |MC   " << pl1[37] << "|" << endl;
    cout << "| " << pl2[13] << "|                                                                       | " << pl2[37] << "|" << endl;
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|PAC    |                                                                       |COOP   |" << endl;
    cout << "|       |                                                                       |FEE    |" << endl;
    cout << "|     " << pl1[12] << "|                                                                       |     " << pl1[38] << "|" << endl;
    cout << "| " << pl2[12] << "|                                                                       | " << pl2[38] << "|" << endl;
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|" << im[5] << "|                                                                       |" << im[21] << "|" << endl;
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|RCH  " << pl1[11] << "|                                                                       |DC   " << pl1[39] << "|" << endl;
    cout << "| " << pl2[11] << "|                                                                       | " << pl2[39] << "|" << endl;
    cout << "|_______|_______________________________________________________________________|_______|" << endl;
    cout << "|DC Tims|" << im[4] << "|" << im[3] << "|NEEDLES|" << im[2] << "|MKV    |TUITION|" << im[1] << "|SLC    |" << im[0] << "|COLLECT|" << endl;
    cout << "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |" << endl;
    cout << "|     " << pl1[10] << "|HH   " << pl1[9] << "|PAS  " << pl1[8] << "|     " << pl1[7] << "|ECH  " << pl1[6] << "|     " << pl1[5] << "|     " << pl1[4] << "|ML   " << pl1[3] << "|     " << pl1[2] << "|AL   " << pl1[1] << "|     " << pl1[0] << "|" << endl;
    cout << "| " << pl2[10] << "| " << pl2[9] << "| " << pl2[8] << "| " << pl2[7] << "| " << pl2[6] << "| " << pl2[5] << "| " << pl2[4] << "| " << pl2[3] << "| " << pl2[2] << "| " << pl2[1] << "| " << pl2[0] << "|" << endl;
    cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" << endl;
}

Game::~Game() {
    for (int i = 0; i < numPlayers; i++) {
        delete players[i];
    }
    delete die1;
    delete die2;
    for (int i = 0; i < numSquares; i++) {
        delete board[i];
    }
    delete [] players;
}



