#include "Player.h"
#include <iostream>


Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

Player::Player(std::string n)
{
    name = n;
}

std::string Player::getName()
{
    return name;
}

void Player::operator=(Player p)
{
    Player::name = p.getName();
}
