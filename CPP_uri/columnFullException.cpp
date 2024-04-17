//
// Created by Simona Istoc on 4/17/2024.
//

#include "../Header/columnFullException.h"

const char *columnFullException::what() const noexcept {
    return "The column is full\n";
}
