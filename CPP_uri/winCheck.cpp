//
// Created by Simona Istoc on 4/3/2024.
//
#include "../Header/winCheck.h"
//initialize win with 0 (the match is not won), when win=1 someone won


winCheck &winCheck::operator=(int winValue) {
    this->win = winValue;
    return *this;
}

int winCheck::getWin() const {
    return win;
}

