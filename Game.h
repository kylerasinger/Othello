#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game();
        virtual ~Game();
        Game(Player p1, Player p2);
        void start();

    protected:

    private:
};

#endif // GAME_H
