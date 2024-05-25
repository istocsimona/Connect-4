#include <iostream>
#include "Header/winCheck.h"
#include "Header/Move.h"
#include "Header/Piece.h"
#include "Header/Player.h"
#include "Header/Board.h"
#include "Header/mainMenu.h"
#include "Header/columnOrLine.h"
#include "Header/rotation.h"
#include <memory>

class levelOne:public mainMenu{
public:
    void execute()const override{
        std::unique_ptr<Player>player1=std::make_unique<Player>();
        std::unique_ptr<Player>player2=std::make_unique<Player>();
        std::cout << "Insert alias for the first player: ";
        std::cin>>*player1;
        std::cout << std::endl;
        std::cout << "Insert alias for the second player: ";
        std::cin>>*player2;
        std::cout << std::endl;


        //declare the game baord
        std::unique_ptr<Board>board=std::make_unique<Board>();

        //decalare the moves. Player1 always starts
        std::unique_ptr<Move>playerMove=std::make_unique<Move>();

        //the column that receives the next piece
        std::unique_ptr<Piece>columnReceivingNextPiece=std::make_unique<Piece>();

        //win=0, if win=1 someone won
        winCheck winGame;
        board->print();
        std::cout << std::endl;
        while (winGame.getWin() == 0) {
            if (playerMove->getMove() == 1) {
                std::cout << player1->getNume() << "'s turn " << std::endl;

                std::cout << "Type the column where you wish to put the next piece: ";
                std::cin>> *columnReceivingNextPiece;
                while (columnReceivingNextPiece->getPiece() - 1 < 0 || columnReceivingNextPiece->getPiece() - 1 > 6 ||
                       board->fullColumn(columnReceivingNextPiece->getPiece() - 1) == 0) {
                    //check if the column exists
                    std::cout << "Column full or does not exist" << std::endl;
                    std::cout << "Type the column where you wish to put the next piece: ";
                    std::cin>> *columnReceivingNextPiece;
                }
                std::cout << std::endl;
                //we put the element on the column we read
                board->setElement(columnReceivingNextPiece->getPiece() - 1, 'o');

                //the piece falls using the gravity function, in t we keep the line the piece stops
                int t = board->gravity(columnReceivingNextPiece->getPiece());
                if (board->check_player(t, columnReceivingNextPiece->getPiece() - 1))
                    winGame.operator=(1);

                //check if the move won the match
                board->print();
                playerMove->setMove(2);
                //switch to player 2
                if (winGame.getWin() == 1)
                    std::cout << "Congratilation " << player1->getNume() << "!!!!!";
                if (board->noWin()==0)
                    std::cout<<"Tie, no win";
            } else {
                std::cout << player2->getNume() << "'s turn " << std::endl;

                std::cout << "Type the column where you wish to put the next piece: ";
                std::cin>> *columnReceivingNextPiece;
                while (columnReceivingNextPiece->getPiece() - 1 < 0 || columnReceivingNextPiece->getPiece() - 1 > 6 ||
                       board->fullColumn(columnReceivingNextPiece->getPiece() - 1) == 0) {//check if the column exists
                    std::cout << "Column full or does not exist" << std::endl;
                    std::cout << "Type the column where you wish to put the next piece: ";
                    std::cin>> *columnReceivingNextPiece;
                }
                std::cout << std::endl;
                board->setElement(columnReceivingNextPiece->getPiece() - 1, 'x');
                int t = board->gravity(columnReceivingNextPiece->getPiece());
                if (board->check_player(t, columnReceivingNextPiece->getPiece() - 1))//crash
                    winGame.operator=(1);


                board->print();
                playerMove->setMove(1);
                if (winGame.getWin() == 1)
                    std::cout << "Congratulation " << player2->getNume() << "!!!!!";
                if (board->noWin()==0)
                    std::cout<<"Tie, no win";
            }

        }
    }
};

class levelTwo:public mainMenu{
public:
    void execute()const override{
        std::unique_ptr<Player>player1=std::make_unique<Player>();
        std::unique_ptr<Player>player2=std::make_unique<Player>();
        std::cout << "Insert alias for the first player: ";
        std::cin>>*player1;
        std::cout << std::endl;
        std::cout << "Insert alias for the second player: ";
        std::cin>>*player2;
        std::cout << std::endl;


        //declare the game baord
        std::unique_ptr<Board>board=std::make_unique<Board>();

        //decalare the moves. Player1 always starts
        std::unique_ptr<Move>playerMove=std::make_unique<Move>();

        //the column that receives the next piece
        std::unique_ptr<Piece>columnReceivingNextPiece=std::make_unique<Piece>();

        //win=0, if win=1 someone won
        winCheck winGame;
        board->printForLevel2();
        std::cout << std::endl;
        while (winGame.getWin() == 0) {
            if (playerMove->getMove() == 1) {
                std::cout << player1->getNume() << "'s turn " << std::endl;

                std::cout << "Type the column where you wish to put the next piece: ";
                std::cin>> *columnReceivingNextPiece;
                while (columnReceivingNextPiece->getPiece() - 1 < 0 || columnReceivingNextPiece->getPiece() - 1 > 6 ||
                       board->fullColumn(columnReceivingNextPiece->getPiece() - 1) == 0) {
                    //check if the column exists
                    std::cout << "Column full or does not exist" << std::endl;
                    std::cout << "Type the column where you wish to put the next piece: ";
                    std::cin>> *columnReceivingNextPiece;
                }
                std::cout << std::endl;
                //we put the element on the column we read
                board->setElement(columnReceivingNextPiece->getPiece() - 1, 'o');

                //the piece falls using the gravity function, in t we keep the line the piece stops
                board->gravity(columnReceivingNextPiece->getPiece());
                board->printForLevel2();

                columnOrLine chooseColumnOrLine;//we choose if we want to rotate a column or a line
                std::cout<<"Do you wish to rotate a line or a column? (l-line, c-column, anything else-pass): ";
                operator>>(std::cin, chooseColumnOrLine);

                rotation choose;
                switch(chooseColumnOrLine.getChooseColumnOrLine()){
                    case 'l':
                        std::cout<<"What line do you wish to rotate?";
                        operator>>(std::cin, choose);
                        board->rotateLine(choose.getWhatLineOrColumnToRotate());
                        break;
                    case 'c':
                        std::cout<<"What collumn do you wish to rotate?";
                        operator>>(std::cin, choose);
                        board->rotateCollumn(choose.getWhatLineOrColumnToRotate());
                        break;
                    default:
                        std::cout<<"Pass\n";
                        break;
                }

                for(int line=1; line<8; line++)
                    for(int column=0; column<7; column++)
                        if (board->check_player(line, column)==1)
                            winGame.operator=(1);

                //check if the move won the match
                board->printForLevel2();
                playerMove->setMove(2);
                //switch to player 2
                if (winGame.getWin() == 1)
                    std::cout << "Congratilation " << player1->getNume() << "!!!!!";
                if (board->noWin()==0)
                    std::cout<<"Tie, no win";
            } else {
                std::cout << player2->getNume() << "'s turn " << std::endl;

                std::cout << "Type the column where you wish to put the next piece: ";
                std::cin>> *columnReceivingNextPiece;
                while (columnReceivingNextPiece->getPiece() - 1 < 0 || columnReceivingNextPiece->getPiece() - 1 > 6 ||
                       board->fullColumn(columnReceivingNextPiece->getPiece() - 1) == 0) {//check if the column exists
                    std::cout << "Column full or does not exist" << std::endl;
                    std::cout << "Type the column where you wish to put the next piece: ";
                    std::cin>> *columnReceivingNextPiece;
                }
                std::cout << std::endl;
                board->setElement(columnReceivingNextPiece->getPiece() - 1, 'x');
                board->gravity(columnReceivingNextPiece->getPiece());
                board->printForLevel2();

                columnOrLine chooseColumnOrLine;//we choose if we want to rotate a column or a line
                std::cout<<"Do you wish to rotate a line or a column? (l-line, c-column, anything else-pass): ";
                operator>>(std::cin, chooseColumnOrLine);

                rotation choose;
                switch(chooseColumnOrLine.getChooseColumnOrLine()){
                    case 'l':
                        std::cout<<"What line do you wish to rotate?";
                        operator>>(std::cin, choose);
                        board->rotateLine(choose.getWhatLineOrColumnToRotate());
                        break;
                    case 'c':
                        std::cout<<"What collumn do you wish to rotate?";
                        operator>>(std::cin, choose);
                        board->rotateCollumn(choose.getWhatLineOrColumnToRotate());
                        break;
                    default:
                        std::cout<<"Pass\n";
                        break;
                }

                for(int line=1; line<8; line++)
                    for(int column=0; column<7; column++)
                        if (board->check_player(line, column)==1)
                            winGame.operator=(1);


                board->printForLevel2();
                playerMove->setMove(1);
                if (winGame.getWin() == 1)
                    std::cout << "Congratulation " << player2->getNume() << "!!!!!";
                if (board->noWin()==0)
                    std::cout<<"Tie, no win";
            }

        }
    }
};

class levelThree:public mainMenu{
public:
    void execute() const override{
        std::unique_ptr<Player>player1=std::make_unique<Player>();
        std::unique_ptr<Player>player2=std::make_unique<Player>();
        std::cout << "Insert alias for the first player: ";
        std::cin>>*player1;
        std::cout << std::endl;
        std::cout << "Insert alias for the second player: ";
        std::cin>>*player2;
        std::cout << std::endl;


        //declare the game baord
        std::unique_ptr<Board>board=std::make_unique<Board>();

        //decalare the moves. Player1 always starts
        std::unique_ptr<Move>playerMove=std::make_unique<Move>();

        //the column that receives the next piece
        std::unique_ptr<Piece>columnReceivingNextPiece=std::make_unique<Piece>();

        //win=0, if win=1 someone won
        winCheck winGame;
        board->print();
        std::cout << std::endl;
        while (winGame.getWin() == 0) {
            if (playerMove->getMove() == 1) {
                std::cout << player1->getNume() << "'s turn " << std::endl;

                std::cout << "Type the column where you wish to put the next piece: ";
                std::cin>> *columnReceivingNextPiece;
                while (columnReceivingNextPiece->getPiece() - 1 < 0 || columnReceivingNextPiece->getPiece() - 1 > 6 ||
                       board->fullColumn(columnReceivingNextPiece->getPiece() - 1) == 0) {
                    //check if the column exists
                    std::cout << "Column full or does not exist" << std::endl;
                    std::cout << "Type the column where you wish to put the next piece: ";
                    std::cin>> *columnReceivingNextPiece;
                }
                std::cout << std::endl;
                //we put the element on the column we read
                board->setElement(columnReceivingNextPiece->getPiece() - 1, 'o');
                //the piece falls using the gravity function, in t we keep the line the piece stops
                board->gravity(columnReceivingNextPiece->getPiece());
                board->print();
                board->rotate90degreesClockWise();

                //check if the move won the match
                for(int line=1; line<8; line++)
                    for(int column=0; column<7; column++)
                            if (board->check_player(line, column)==1)
                                winGame.operator=(1);
                board->print();

                //switch to player 2
                playerMove->setMove(2);
                if (winGame.getWin() == 1)
                    std::cout << "Congratilation " << player1->getNume() << "!!!!!";
                if (board->noWin()==0)
                    std::cout<<"Tie, no win";
            } else {
                std::cout << player2->getNume() << "'s turn " << std::endl;

                std::cout << "Type the column where you wish to put the next piece: ";
                std::cin>> *columnReceivingNextPiece;
                while (columnReceivingNextPiece->getPiece() - 1 < 0 || columnReceivingNextPiece->getPiece() - 1 > 6 ||
                       board->fullColumn(columnReceivingNextPiece->getPiece() - 1) == 0) {//check if the column exists
                    std::cout << "Column full or does not exist" << std::endl;
                    std::cout << "Type the column where you wish to put the next piece: ";
                    std::cin>> *columnReceivingNextPiece;
                }
                std::cout << std::endl;
                board->setElement(columnReceivingNextPiece->getPiece() - 1, 'x');
                //the piece falls using the gravity function, in t we keep the line the piece stops
                board->gravity(columnReceivingNextPiece->getPiece());
                board->print();
                board->rotate90degreesClockWise();

                //check if the move won the match
                for(int line=1; line<8; line++)
                    for(int column=0; column<7; column++)
                        if (board->check_player(line, column)==1)
                            winGame.operator=(1);
                board->print();
                playerMove->setMove(1);
                if (winGame.getWin() == 1)
                    std::cout << "Congratulation " << player2->getNume() << "!!!!!";
                if (board->noWin()==0)
                    std::cout<<"Tie, no win";
            }

        }
    }
};

class chooseMenuFactory:public menuFactory{
private:
    int option{};
public:
    virtual void display(){
        std::cout<<"Main Menu\n";
        std::cout<<"1. Simple game\n";
        std::cout<<"2. Switch line/column \n";
        std::cout<<"3. Clock Board\n";
    }
    friend std::istream &operator>>(std::istream &in, chooseMenuFactory &choose){
        std::cout<<"Choose : ";
        in>>choose.option;
        return in;
    }
    [[nodiscard]]int getOption() const{
        return option;
    }
    std::unique_ptr<mainMenu>createMenuOption(const int option) const override{
        switch (option) {
            case 1:
                return std::make_unique<levelOne>();
                break;
            case 2:
                return std::make_unique<levelTwo>();
                break;
            case 3:
                return std::make_unique<levelThree>();
                break;
            default:
                throw std::invalid_argument("No option");
                break;
        }
    }
};

int main() {
    chooseMenuFactory chooseOption;
    levelOne one;
    levelTwo two;
    levelThree three;

    chooseOption.display();
    operator>>(std::cin, chooseOption);
    switch (chooseOption.getOption()) {
        case 1:
            std::cout << "Starting Level 1...\n\n";
            one.execute();
            break;
        case 2:
            std::cout << "Starting Level 2...\n";
            two.execute();
            break;
        case 3:
            std::cout << "Starting Level 3...\n";
            three.execute();
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
    }

    return 0;
}
