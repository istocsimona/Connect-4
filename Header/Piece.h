//
// Created by Simona Istoc on 4/3/2024.
//

#ifndef OOP_PIECE_H
#define OOP_PIECE_H
#include <iostream>

class Piece {
//    we keep track of the column we place the pice
private:
    int columnPiece;
    char columnOrLine;
public:
    Piece() = default;

    [[nodiscard]]int getPiece() const;

    friend std::istream &operator>>(std::istream &in, Piece &piece);

    ~Piece() = default;
};


#endif //OOP_PIECE_H
