//
// Created by Simona Istoc on 5/24/2024.
//

#ifndef OOP_COLUMNORLINE_H
#define OOP_COLUMNORLINE_H


#include <iostream>

class columnOrLine{
private:
    char chooseColumnOrLine;

public:
    char getChooseColumnOrLine() const;

    friend std::istream &operator>>(std::istream &in, columnOrLine &choose);
};


#endif //OOP_COLUMNORLINE_H
