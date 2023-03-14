#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Player.h"
#include "Position.h"

class Board
{
    public:
        Board();
        virtual ~Board();
        void drawBoard();
        static Board load();
        Board(Player p1, Player p2, int start);
        Board(std::string save_file);
        void play();
        void makeMove(int pos);
        bool checkMove(int pos);


        void setBoardPositions(std::string s);
        //Position getBoardPositions(short n);

        void loadStartBoards();

        void setPlayerOne(Player p);
        void setPlayerTwo(Player p);
        void setPlayerCurrent(Player p);

        Player getPlayerOne();
        Player getPlayerTwo();
        Player getPlayerCurrent();





    protected:

    private:
        Player first; //BLACK
        Player second; //WHITE
        Player current;
        Position boardPositions[64];
        //*Position startBoardOne[64];
        //*Position startBoardTwo[64];

        void save();
        void takeTurn();

};

#endif // BOARD_H
