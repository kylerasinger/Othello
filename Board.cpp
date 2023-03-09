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
    std::string verticalIndex = "12345678";
    std::cout << "\n\n\ta b c d e f g h\n\n\n";

    short counter = 0;
    for(int i = 0; i < 8; i++)
    {
        while(counter < 8){
            if(counter == 0){std::cout << verticalIndex[i] << '\t';}
            std::cout << boardPositions[counter+(i*8)].getPiece() << ' ';
            counter++;
        }
        counter = 0;
        std::cout << "\n";
    }
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
    short counter = 0;
    std::ostringstream ssFirst;
    std::ostringstream ssSecond;
    std::ostringstream ssCurrent;
    std::ostringstream ssBoard;
    for(int i = 0; i < save_file.length(); i++)
    {
        if(counter < 3){
            //get players
            if(counter == 0 && save_file[i] != '\n')
            {
                ssFirst << save_file[i];
            }else if(counter == 0 && save_file[i] == '\n')
            {
                //std::cout << "\nfirst name is: " << ssFirst.str();
                counter++;
            }else if(counter == 1 && save_file[i] != '\n')
            {
                ssSecond << save_file[i];
            }else if(counter == 1 && save_file[i] == '\n')
            {
                //std::cout << "\nsecond name is: " << ssSecond.str();
                counter++;
            }else if(counter == 2 && save_file[i] != '\n')
            {
                ssCurrent << save_file[i];
            }else if(counter == 2 && save_file[i] == '\n')
            {
                //std::cout << "\ncurrent name is: " << ssCurrent.str();
                counter++;
            }
        }else
        {//gets board
            if(save_file[i] != '\n')
            {
                ssBoard << save_file[i];
            }
        }
    }
    //std::cout << "\nBoard str is : " << ssBoard.str();


    Player first(ssFirst.str());
    Player second(ssSecond.str());
    Player current(ssCurrent.str());
    setBoardPositions(ssBoard.str());

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

void Board::setBoardPositions(std::string s)
{

    for(int i = 0; i < s.length(); i++)
    {
        boardPositions[i].setPiece(s[i]);
    }
    //draws board, dont need this after
    //Board::drawBoard();
}

