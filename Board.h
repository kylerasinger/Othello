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

        void setBoardPositions(std::string s);
        //Position getBoardPositions(short n);

        void loadStartBoards();


    protected:

    private:
        Player first;
        Player second;
        Player current;
        Position boardPositions[64];
        //*Position startBoardOne[64];
        //*Position startBoardTwo[64];

        void save();
        void takeTurn();

};

#endif // BOARD_H
