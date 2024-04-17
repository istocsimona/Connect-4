//
// Created by Simona Istoc on 4/3/2024.
//

#ifndef OOP_BOARD_H
#define OOP_BOARD_H


#include <algorithm>

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

    int check_playerLevelTwoAndThree(int line, int column);
};


#endif //OOP_BOARD_H
