//
// Created by Simona Istoc on 4/3/2024.
//

#include "../Header/Piece.h"
int Piece::getPiece() const {
    return columnPiece;
}

std::istream &operator>>(std::istream &in, Piece &piece) {
    in >> piece.columnPiece;
    return in;
}