//
// Created by Simona Istoc on 4/17/2024.
//

#ifndef OOP_NOONEWINEXCEPTION_H
#define OOP_NOONEWINEXCEPTION_H

#include <exception>

class noOneWinException: public std::exception{
public:
    const char* what() const noexcept override;
};


#endif //OOP_NOONEWINEXCEPTION_H
