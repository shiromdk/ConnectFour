#include <iostream>
#include "src/ConnectFour.h"

int main() {
    ConnectFour * game = new ConnectFour();
    vector<int> moves = game->listMoves();
    for(int move: moves){
        cout << move << endl;
    }

    return 0;
}
