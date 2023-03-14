#include "Game.h"
#include "Player.h"
#include "Board.h"

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

    //std::cout << "TEST OF NAME: " << p1.getName() << p1.getName() << p1.getName();

    Board newBoard(p1, p2, firstTurn);
    setBoard(newBoard);
    //std::cin >> firstTurn;

    //ask for which board
    //*newBoard.loadStartBoards();

}

void Game::start() //holds game loop?
{
    bool quitGame = false;
    while(!quitGame)
    {
        board.play();
    }
}

void Game::setBoard(Board b)
{
    board = b;
}

Board Game::getBoard()
{
    return board;
}

