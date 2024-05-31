//
// Created by Simona Istoc on 4/15/2024.
//

#ifndef OOP_MAINMENU_H
#define OOP_MAINMENU_H

#include <iostream>
#include <memory>
//kinda factory method with the three levels
class mainMenu{//menuOption

public:
    virtual ~mainMenu()=default;
    virtual void execute()const=0;
};

class menuFactory{
public:
    virtual ~menuFactory()=default;
    virtual std::unique_ptr<mainMenu> createMenuOption(const int opt)const=0;

};


#endif //OOP_MAINMENU_H
