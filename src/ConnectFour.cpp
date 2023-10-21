//
// Created by c3131 on 20/10/2023.
//

#include "ConnectFour.h"
#include "typedefs.h"
#include <algorithm>

#define get_bit(bitboard, square)(bitboard & (1ULL<< square)

U64 ConnectFour::getMoveCount() {
    return moves.size();
}

bool ConnectFour::isWin(U64 bitboard) {
    vector<int> directions = {1, 7, 6, 8};
    U64 bb;
    for(int direction : directions) {
        bb = bitboard & (bitboard >> direction);
        if ((bb & (bb >> (2 * direction))) != 0) return true;
    }
    return false;
}

void ConnectFour::undoMove() {
    int col = moves[--moveCounter];
    long move = 1L << --height[col];
    if(moveCounter % 2 == 0){
        playerOneBitboard.setBoard(playerOneBitboard.getBoard() ^ move) ;
    }else{
        playerTwoBitboard.setBoard(playerTwoBitboard.getBoard() ^ move) ;
    }
}

void ConnectFour::makeMove(int column) {
    long move = 1L << height[column]++;
    if(moveCounter % 2 == 0){
        playerOneBitboard.setBoard(playerOneBitboard.getBoard() ^ move) ;
    }else{
        playerTwoBitboard.setBoard(playerTwoBitboard.getBoard() ^ move) ;
    }
    moves[moveCounter]++;

}

ConnectFour::ConnectFour(){
    moveCounter = 0;
    height  = {0,7,14,21,28,35,42};
}

vector<int> ConnectFour::listMoves() {
    vector<int> moves;
    long TOP = 0b1000000100000010000001000000100000010000001000000L;
    for(int col = 0; col<=6;col++){
        if ((TOP & (1L << height[col])) == 0) moves.push_back(col);
    }
    return moves;
}

void ConnectFour::displayBoard(U64 board) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            int exp = get_bit(board, square) ? 1 : 0);
            cout << " " << exp;
        }
        cout << endl;
    }
}



