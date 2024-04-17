#include "../Header/mainMenu.h"

//
// Created by Simona Istoc on 4/15/2024.
//
void mainMenu::display() {
    std::cout<<"Main Menu\n";
    std::cout<<"1. Simple game\n";
    std::cout<<"2. Switch line/column \n";
    std::cout<<"3. Clock Board\n";
}

std::istream &operator>>(std::istream &in, mainMenu &menuItem) {
    std::cout<<"Choose : ";
    in>>menuItem.option;
    return in;
}

int mainMenu::getOption() const {
    return option;
}