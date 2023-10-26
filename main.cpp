#include <iostream>
#include "src/ConnectFour.h"

ConnectFour * game;

int main() {
    game = new ConnectFour();
    vector<int> moves = game->listMoves();
    game->startNewGame();
    return 0;
}
