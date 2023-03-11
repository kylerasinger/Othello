#include "Game.h"
#include "Player.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

Game::Game(Player p1, Player p2)
{
    int firstTurn;

    std::cout << "\n\nWho goes first?\n     1. " << p1.getName() << "\n     2. " << p2.getName() << std::endl;
    std::cin >> firstTurn;

    Board newBoard(p1, p2, firstTurn);

    //ask for which board
    //*newBoard.loadStartBoards();

}

void Game::start()
{

}

void Game::setBoard(Board b)
{
    board = b;
}

Board Game::getBoard()
{
    return board;
}
