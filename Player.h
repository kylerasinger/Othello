#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
    public:
        Player();
        virtual ~Player();
        Player(std::string n);
        std::string getName();

    protected:

    private:
        std::string name;
};

#endif // PLAYER_H
