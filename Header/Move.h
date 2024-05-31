//
// Created by Simona Istoc on 4/3/2024.
//

#ifndef OOP_MOVE_H
#define OOP_MOVE_H
#include <iostream>
class Move {
//    we keep track of the player
private:
    int move{1};
public:
    Move() = default;
    void setMove(const int &move);
    [[nodiscard]] int getMove() const;
    ~Move() = default;
};


#endif //OOP_MOVE_H
