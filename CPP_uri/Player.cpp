//
// Created by Simona Istoc on 4/3/2024.
//

#include "../Header/Player.h"


std::istream &operator>>(std::istream &in, Player &player) {
    in >> player.name;
    return in;
}

const std::string &Player::getNume() const {
    return name;
}

//std::ostream &operator<<(std::ostream &out, const Player &player) {
//    out << player.name << std::endl;
//    return out;
//}