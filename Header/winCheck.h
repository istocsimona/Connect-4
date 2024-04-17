//
// Created by Simona Istoc on 4/3/2024.
//

#ifndef OOP_WINCHECK_H
#define OOP_WINCHECK_H

class winCheck {
//    we keep track if the match is won or not
private:
    int win{0};
public:
    winCheck()=default;

    winCheck &operator=(int win);

     [[nodiscard]]int getWin() const;

    ~winCheck() = default;
};


#endif //OOP_WINCHECK_H
