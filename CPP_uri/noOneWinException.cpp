//
// Created by Simona Istoc on 4/17/2024.
//

#include "../Header/noOneWinException.h"
const char *noOneWinException::what() const noexcept {
    return "All the column are full, no one won\n";
}