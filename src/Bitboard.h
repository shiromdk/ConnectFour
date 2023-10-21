//
// Created by c3131 on 20/10/2023.
//

#ifndef CONNECT4_BITBOARD_H
#define CONNECT4_BITBOARD_H


#include "typedefs.h"

class Bitboard {
private:
    U64 board;
public:
    Bitboard();
    U64 getBoard() const;
    void setBoard(U64 newBoard);
};


#endif //CONNECT4_BITBOARD_H
