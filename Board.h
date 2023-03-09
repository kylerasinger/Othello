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
        Board load();
        Board(Player p1, Player p2, int start);
        Board(std::string save_file);
        void play();

        void setFirst(std::string s);
        void setSecond(std::string s);
        void setCurrent(std::string s);

    protected:

    private:
        Player first;
        Player second;
        Player current;
        Position boardPositions[64];

        void save();
        void takeTurn();
};

#endif // BOARD_H
