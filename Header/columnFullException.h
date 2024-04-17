//
// Created by Simona Istoc on 4/17/2024.
//

#ifndef OOP_COLUMNFULLEXCEPTION_H
#define OOP_COLUMNFULLEXCEPTION_H


#include <exception>

class columnFullException: public std::exception{
public:
    const char* what() const noexcept override;
};


#endif //OOP_COLUMNFULLEXCEPTION_H
