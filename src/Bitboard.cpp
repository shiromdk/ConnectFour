//
// Created by c3131 on 20/10/2023.
//

#include "Bitboard.h"

Bitboard::Bitboard() {
    board = 0ULL;
}

U64 Bitboard::getBoard() const {
    return board;
}

void Bitboard::setBoard(U64 newBoard) {
    board = newBoard;
}

