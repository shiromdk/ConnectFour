//
// Created by c3131 on 20/10/2023.
//


// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>
#include "typedefs.h"
#include "Bitboard.h"

#ifndef CONNECT4_CONNECTFOUR_H
#define CONNECT4_CONNECTFOUR_H

using namespace  std;

class ConnectFour {
private:
    int moveCounter;
    vector<int> height; // Serves as memory of where the next token goes given the column
    vector<int> moves;

    Bitboard playerOneBitboard;
    Bitboard playerTwoBitboard;

public:
    ConnectFour();
    U64 getMoveCount();
    void makeMove(int column);
    void undoMove();
    bool isWin(U64 bb);
    vector<int> listMoves();
    static void displayBoard(U64 board);
};


#endif //CONNECT4_CONNECTFOUR_H
