#include "Board.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Board::Board()
{
    //ctor
}

Board::~Board()
{
    //dtor
}

void Board::drawBoard()
{

}

Board Board::load()
{
    std::string inputFileName;
    std::cout << "Input save file name (example_save.txt) ";
    std::cin >> inputFileName;

    //std::ifstream inputFile;
    //inputFile.open(inputFileName);
    std::ifstream boardFile(inputFileName);
    std::ostringstream ss;
    //ss << inputFile.rdbuf();
    //std::string inputFileString = ss.str();

    int current_line = 0;
    std::string line;
    std::ostringstream ssBoard;
    while(!boardFile.eof())
    {
        current_line++;
        getline(boardFile, line);
        ssBoard << line;
        ssBoard << "\n";

    }

    std::string boardString = ssBoard.str();

    Board importedSave(boardString);
    return importedSave;
}

Board::Board(Player p1, Player p2, int start)
{

}

Board::Board(std::string save_file)
{

}

void Board::play()
{

}

void Board::save()
{

}

void Board::takeTurn()
{

}

void Board::setFirst(std::string s)
{
    Player first(s);
}

void Board::setSecond(std::string s)
{
    Player second(s);
}

void Board::setCurrent(std::string s)
{
    Player third(s);
}
