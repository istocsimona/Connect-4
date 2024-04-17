//
// Created by Simona Istoc on 4/3/2024.
//

#include "../Header/Board.h"
#include <iostream>

int Board::check_player(int line, int column) {
    //line check
    int nr = 0;
    for (int j = 0; j < 6 && nr < 3; j++)
        if ((board[line][j] == board[line][j + 1]) && board[line][j] != '^' && board[line][j + 1] != '^')
            nr++;
        else nr = 0;
    if (nr >= 3) return 1;//winner

    //column check
    nr = 0;
    for (int i = line; i < 7 && nr < 3; i++)
        if ((board[i][column] == board[i + 1][column]) && board[i][column] != '^' && board[i + 1][column] != '^')
            nr++;
        else nr = 0;
    if (nr >= 3) return 1;

    //diagonally check / down
    nr = 0;
    int samePiece = 1;
    int i = line, j = column;
    while (samePiece == 1) {
        if (board[line][column] == board[i + 1][j - 1]) {
            nr++;
            i = i + 1;
            j = j - 1;
        } else samePiece = 0;
    }
    if (nr >= 3)
        return 1; //winner

    //diagonally check / up
    nr = 0;
    samePiece = 1;
    i = line;
    j = column;
    while (samePiece == 1) {
        if (board[line][column] == board[i - 1][j + 1]) {
            nr++;
            i = i - 1;
            j = j + 1;
        } else samePiece = 0;
    }
    if (nr >= 3)
        return 1; //winner

    //diagonally check \ down
    nr = 0;
    samePiece = 1;
    i = line;
    j = column;
    while (samePiece == 1) {
        if (board[line][column] == board[i + 1][j + 1]) {
            nr++;
            i = i + 1;
            j = j + 1;
        } else samePiece = 0;
    }
    if (nr >= 3)
        return 1;// winner

    //diagonally check \ up
    nr = 0;
    samePiece = 1;
    i = line;
    j = column;
    while (samePiece == 1) {
        if (board[line][column] == board[i - 1][j - 1]) {
            nr++;
            i = i - 1;
            j = j - 1;
        } else samePiece = 0;
    }
    if (nr >= 3)
        return 1; //winner
    return 0;//round_ongoing
}

//void Board::printForLevel2() {
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++)
//            std::cout << board[i][j] << " ";
//        std::cout << std::endl;
//    }
//}
void Board::print() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
}


//nu merge
class columnFullException:public std::exception{
public:
    const char* what() const noexcept override{
        return "The column is full, no one won\n";
    }
};
int Board::fullColumn(int column) {
    try{
        if (board[1][column] == '^')
            throw columnFullException();//column full
    }
    catch (columnFullException &e){
        std::cout<<"Exceptie custom "<<e.what()<<'\n';
    }
    catch (std::exception &e) {
        std::cout << "Exceptie default " << e.what() << '\n';
    }
    return 1;//column not full
}

int Board::gravity(int column) {
//    the element will be placed on the first line and will fall until the last piece met
    int i = 1;
    while (board[i + 1][column - 1] == '^') {
        std::swap(board[i][column - 1], board[i + 1][column - 1]);
        i++;
    }
    return i;
}

void Board::setElement(int column, char value) {
//    set the element the the first line and the specific column
    if (column >= 0 && column < 7)
        board[1][column] = value;
}

Board::Board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            board[i][j]='^';
            if(i==0) board[i][j]='1'+j;
            if(j==7) board[i][j]='0'+i;
            if(i==0 && j==7) board[i][j]=' ';
        }
}



class noOneWinException:public std::exception{
public:
    const char* what() const noexcept override{
        return "All the column are full, no one won\n";
    }
};
int Board::noWin() {
    int nr=0;
    for(int j=0; j<8; j++)
        if(board[1][j]!='^')
            nr++;
    try{
        if(nr==7)
            throw noOneWinException();
    }
    catch (noOneWinException &e){
        std::cout<<"Exceptie custom "<<e.what()<<'\n';
    }
    catch (std::exception &e) {
        std::cout << "Exceptie default " << e.what() << '\n';
    }

    return 1;
}
