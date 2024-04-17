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

//    void rotate90degreesClockWise(){
//        int matrixrotate[7][7], iRotate=0, jRotate=6;
//        for(int i=1; i<=7; i++){
//            for(int j=0; j<=6; j++){
//                matrixrotate[iRotate][jRotate]=board[i][j];
//                iRotate++;
//            }
//            jRotate--;
//            iRotate=0;
//        }
//
//        for(int i=1; i<=7; i++)
//            for(int j=0; j<=6; j++)
//                board[i][j]=matrixrotate[i-1][j];
//        //check all the pieces if they fall
//        for(int i=6; i>=1; i--)
//            for(int j=0; j<=6; j++)
//                while (board[i + 1][j] == '^')
//                     std::swap(board[i][j], board[i + 1][j]);
//    }



    int noWin();

    void setElement(int column, char value);

    ~Board() = default;

};


#endif //OOP_BOARD_H
