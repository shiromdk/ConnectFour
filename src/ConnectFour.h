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
    int getMoveCount();
    void makeMove(int column);
    bool gameOver();
    void undoMove();
    static bool isWin(U64 bb);
    vector<int> listMoves();
    static void displayBoard(U64 board);
    static void displayBoard(U64 boardOne, U64 boardTwo);
    Bitboard getPlayerBoard(bool isPlayerOne);
    void startNewGame();
};


#endif //CONNECT4_CONNECTFOUR_H
