//
// Created by Simona Istoc on 5/24/2024.
//

#include "../Header/rotation.h"

int rotation::getWhatLineOrColumnToRotate() const {
    return whatLineOrColumnToRotate;
}

std::istream &operator>>(std::istream &in, rotation &choose) {
    std::cout<<"\nChoose : ";
    in>>choose.whatLineOrColumnToRotate;
    return in;
}


