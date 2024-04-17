//
// Created by Simona Istoc on 4/3/2024.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>

class Player {
private:
    std::string name;

public:
    Player() = default;
    friend std::istream &operator>>(std::istream &in, Player &player);
    [[nodiscard]]const std::string &getNume() const;
    //friend std::ostream &operator<<(std::ostream &out, const Player &player);
    ~Player() = default;
};


#endif //OOP_PLAYER_H
