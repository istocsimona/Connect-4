//
// Created by Simona Istoc on 4/3/2024.
//

#ifndef OOP_BOARD_H
#define OOP_BOARD_H


#include <algorithm>
#include <iostream>

class Board {
private:
    char board[8][8];

public:
    Board();

    int check_player(int line, int column);

    void print();

    //void printForLevel2();

    int fullColumn(int column);

    int gravity(int column);

    void rotate90degreesClockWise();

    int noWin();

    void setElement(int column, char value);

    ~Board() = default;

    void printForLevel2();

    void rotateLine(int theLine);

    void rotateCollumn(int theCollumn);
};


#endif //OOP_BOARD_H
