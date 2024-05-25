//
// Created by Simona Istoc on 5/24/2024.
//

#ifndef OOP_ROTATION_H
#define OOP_ROTATION_H
#include <iostream>

class rotation {
private:
    int whatLineOrColumnToRotate;
public:
    int getWhatLineOrColumnToRotate() const;
    rotation()=default;
    ~rotation()=default;
    friend std::istream &operator>>(std::istream &in, rotation &choose);

};


#endif //OOP_ROTATION_H
