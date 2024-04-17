//
// Created by Simona Istoc on 4/15/2024.
//

#ifndef OOP_MAINMENU_H
#define OOP_MAINMENU_H

#include <iostream>
class Menu{
private:
    virtual void display()=0;
};

class mainMenu:public Menu{
private:
    int option{};
public:
    void display() override;
    friend std::istream &operator>>(std::istream &in, mainMenu &menuItem);
    [[nodiscard]]int getOption() const;

};
#endif //OOP_MAINMENU_H
