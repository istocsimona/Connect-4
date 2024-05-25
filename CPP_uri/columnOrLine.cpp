//
// Created by Simona Istoc on 5/24/2024.
//

#include "../Header/columnOrLine.h"
char columnOrLine::getChooseColumnOrLine() const {
    return chooseColumnOrLine;
}


std::istream &operator>>(std::istream &in, columnOrLine &choose) {
    std::cout<<"\nChoose : ";
    in>>choose.chooseColumnOrLine;
    return in;
}
