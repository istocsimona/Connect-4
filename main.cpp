#include <iostream>
#include "Header/winCheck.h"
#include "Header/Move.h"
#include "Header/Piece.h"
#include "Header/Player.h"
#include "Header/Board.h"
#include "Header/mainMenu.h"
#include <memory>

class levelOne:public mainMenu{
public:
    static void run(){
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
//class leveTwo:public mainMenu{};
class levelThree:public mainMenu{
public:
    static void run(){
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
                board->rotate90degreesClockWise();
                board->print();
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
                board->rotate90degreesClockWise();
                board->print();
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

int main() {
    mainMenu menuItem;

    levelOne one;
    levelThree three;

    menuItem.display();
    operator>>(std::cin, menuItem);
    switch (menuItem.getOption()) {
        case 1:
            std::cout << "Starting Level 1...\n\n";
            one.run();
            break;
        case 2:
            std::cout << "Starting Level 2...\n";
            break;
        case 3:
            std::cout << "Starting Level 3...\n";
            three.run();
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
    }

    return 0;
}
