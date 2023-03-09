#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        Game(Player p1, Player p2);
        void start();
        void setBoard(Board boardIn);

    protected:

    private:
        Board board;
};

#endif // GAME_H
