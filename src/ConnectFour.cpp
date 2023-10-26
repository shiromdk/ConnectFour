//
// Created by c3131 on 20/10/2023.
//

#include "ConnectFour.h"
#include "typedefs.h"
#include <algorithm>

#define get_bit(bitboard, square)(bitboard & (1ULL<< square)

int ConnectFour::getMoveCount(){
    return moveCounter;
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
        cout << "player one move" << endl;
        playerOneBitboard.setBoard(playerOneBitboard.getBoard() ^ move) ;
    }else{
        cout << "player two move" << endl;
        playerTwoBitboard.setBoard(playerTwoBitboard.getBoard() ^ move) ;
    }

    moves[moveCounter]++;
    moveCounter++;

}

ConnectFour::ConnectFour(){
    moveCounter = 0;
    height  = {0,7,14,21,28,35,42};
}

vector<int> ConnectFour::listMoves() {
    vector<int> availableMoves;
    U64 TOP = 0b1000000100000010000001000000100000010000001000000L;
    for(int col = 0; col<=6;col++){
        if ((TOP & (1L << height[col])) == 0) availableMoves.push_back(col);
    }
    return availableMoves;
}

void ConnectFour::displayBoard(U64 board) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 7; file++) {
            int square = rank * 7 + file;
            int exp = get_bit(board, square) ? 1 : 0);
            cout << " " << exp;
        }
        cout << endl;
    }
}
void ConnectFour::displayBoard(U64 boardOne, U64 boardTwo) {
    for (int rank = 0; rank < 7; rank++) {
        for (int file = 0; file < 7; file++) {
            int square = rank * 7 + file;
            string pOneBits = get_bit(boardOne, square) ? "X" : "0");
            string pTwoBits = get_bit(boardTwo, square) ? "Y" : "0");
            if(pOneBits == "X"){
                cout << " " << pOneBits;
            }else if(pTwoBits=="Y"){
                cout << " " << pTwoBits;
            }else{
                cout << " " << "0";
            }

        }
        cout << endl;

    }
    cout << "Board: " << (boardOne |boardTwo) << endl;
}

Bitboard ConnectFour::getPlayerBoard(bool isPlayerOne) {
    if(isPlayerOne){
        return playerOneBitboard;
    }else{
        return playerTwoBitboard;
    }
}

void ConnectFour::startNewGame() {
    playerOneBitboard.setBoard(  0ULL);
    playerTwoBitboard.setBoard(0ULL);
    for(int i = 0;i<7;i++){
        moves.push_back(0);
    }
    while(!gameOver()){
        int currentMoveCount = getMoveCount();
        cout << "Moves made = " << currentMoveCount <<endl;
        if(currentMoveCount%2==0){
            cout << "It is Player One's turn" << endl;
            cout << "Enter a move" << endl;
            vector<int> currentAvailableMoves = listMoves();
            for(int moveToMake:currentAvailableMoves){
                cout << moveToMake << " ";
            }
            cout << endl;
            string tempString;
            getline(cin, tempString);
            makeMove(stoi(tempString));
        }else{
            cout << "It is Player Two's turn" << endl;
            cout << "Enter a move" << endl;
            vector<int> currentAvailableMoves = listMoves();
            for(int moveToMake:currentAvailableMoves){
                cout << moveToMake << " ";
            }
            cout << endl;
            string tempString;
            getline(cin, tempString);
            makeMove(stoi(tempString));
        }
        displayBoard(playerOneBitboard.getBoard(),playerTwoBitboard.getBoard());
    }
}

bool ConnectFour::gameOver() {
    if(
            isWin(playerOneBitboard.getBoard())|
    isWin(playerTwoBitboard.getBoard())){
        cout << "ITS JOVER" << endl;
        return true;
    }
    return false;
}





