#include <iostream>
#include "game.h"
#include <string>
#include <fstream>
#include <cstring>

int main(int argc, const char * argv[]) {
    string filename = "";
    ifstream *inFile;
    bool test = false;
    bool read = false;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "-load")) {
            read = true;
            filename = argv[i + 1];
        }
        if (!strcmp(argv[i], "-testing")) {
            test = true;
        }
    }
    Game *game = new Game;
    if (read) {
        inFile = new ifstream( filename.c_str() );
        game->play(test, true, inFile); // first one is testing, second is loading file
        delete inFile;
    } else {
        game->play(test, false);
    }
    delete game;
}

