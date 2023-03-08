#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Player.h"

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

    protected:

    private:
        void save();
        void takeTurn();
};

#endif // BOARD_H
