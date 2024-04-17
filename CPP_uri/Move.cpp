//
// Created by Simona Istoc on 4/3/2024.
//

#include "../Header/Move.h"
void Move::setMove(const int &moveValue) {
    Move::move = moveValue;
}

int Move::getMove() const {
    return move;
}

std::ostream &operator<<(std::ostream &out, const Move &move) {
    out << move.move;
}