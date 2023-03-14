#include "Board.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "UnplayablePosition.h"
#include "Position.h"

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
    first = p1;
    second = p2;
    /**
    std::cout << "TEST OF NAME: " << first.getName() << first.getName() << first.getName();
    std::string test;
    std::cin >> test;
    */
    if(start == 1){
        current = p1;
    }else if(start == 2){
        current = p2;
    }
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


    Player firsti(ssFirst.str());
    first = firsti;
    Player secondi(ssSecond.str());
    second = secondi;
    Player currenti(ssCurrent.str());
    current = currenti;
    setBoardPositions(ssBoard.str());
}

void Board::play()
{
    std::cout << "\n\n\nNEW TURN\n\n\n";
    system("CLS");
    { //win condition checker
        int counter = 64;
        for(int i = 0; i < 64; i++){
            if(boardPositions[i].getPiece() == '.'){
                counter--;
            }
        }

        if(counter == 0){ //all positions are full
            //count for winner
            int counterB = 0;
            int counterW = 0;

            for(int i = 0; i < 64; i++){
                if(boardPositions[i].getPiece() == 'B'){
                    counterB++;
                }

                if(boardPositions[i].getPiece() == 'W'){
                    counterW++;
                }
            }

            if(counterB > counterW){
                std::cout << "BLACK IS THE WINNER.\n ";
            }else if(counterW > counterB){
                std::cout << "WHITE IS THE WINNER.\n ";
            }else if(counterW == counterB) {
                std::cout << "THE GAME IS A DRAW.\n ";
            }
        }
    }
    //prompt user options

    Board::drawBoard();

    int input;
    std::cout << "\n\nIt is " << current.getName() << "'s turn.";
    if(current.getName() == first.getName()){std::cout << "\nPlace a BLACK (B) token. ";}
    else if(current.getName() == second.getName()){std::cout << "\nPlace a WHITE (W) token. ";}
    std::cout << "\n\t1. Move\n\t2. Save\n\t3. Concede the game (loser)\n\t4. Forfeit your turn\n";
    std::cin >> input;

    switch(input){
        case 1:{ //1. Move
            int indexY;
            char indexX;
            int indexFinal = 100;
            int flag;

            do{
                flag = 0;
                indexY = 0;
                indexX = 0;
                std::cout << "Enter your move (horizontal index, vertical index): ";
                std::cin >> indexX;
                std::cin >> indexY;
                indexX = indexX - 48;
                std::cout << "indexX = " << indexX << "   indexY = " << indexY << std::endl;

                //convert indexes to 1d array
                int indexXint = (int)(indexX - 48) - 1;
                indexY = indexY - 1;
                indexY = indexY * 8;
                indexFinal = indexY + indexXint;
                //std::cout << "indexXint = " << indexXint << "    indexY = " << indexY << "   indexFinal = " << indexFinal;

                //illegal conditions
                if(indexFinal > 63){flag = 1;}
                if(indexFinal < 0){flag = 2;}
                if(boardPositions[indexFinal].canPlay() == false){flag = 3;}

                //does it flank an opposite token?


                //std::cout << "\nflag: " << flag;
            }while(flag != 0);
            std::cout << "MADE IT OUT OF THE LOOP . ";


            //boardPositions[indexFinal].setPiece(Position::BLACK);


            takeTurn();
            break;
        }
        case 2:{ //2. Save

            break;
        }
        case 3:{ //3. Concede the game
            std::string str1 = first.getName();
            std::string str2 = second.getName();
            std::string strCurrent = current.getName();

            if(strCurrent == str1)
            {
                std::cout << "WHITE IS THE WINNER. " << str2;
            }else if(strCurrent == str2)
            {
                std::cout << "BLACK IS THE WINNER. " << str1;
            }
            char n;
            std::cout << "Save the game? (y/n): ";
            std::cin >> n;
            if(n == 'y'){
                save();

            }
            break;
        }
        case 4:{ //4. Forfeit their turn
            takeTurn();
            break;
        }
    }
}

void Board::save()
{

}

void Board::takeTurn()
{
    //toggles current

    std::string str1 = first.getName();
    std::string str2 = second.getName();
    std::string strCurrent = current.getName();

    std::cout << "\n" << current.getName() << "'s turn is now over. ";
    if(strCurrent == str1)
    {
        //std::cout << "current == first" ;
        current = second;
        //std::cout << "the current name is now " << current.getName();
    }else if(strCurrent == str2)
    {
        //std::cout << "current == second";
        current = first;
    }

}

void Board::setBoardPositions(std::string s)
{

    for(int i = 0; i < s.length(); i++)
    {
        Board::boardPositions[i].setPiece(s[i]);
    }
}

void Board::makeMove(int pos)
{
    /**
                OUTFLANK PSEUDOCODE
                N

                NE

                E

                SE

                S

                SW

                W

                NW
                */
}

//getters and setters
bool Board::checkMove(int pos)
{
    int flag = 0;
    bool loop = true;
    char selfPiece;
    if(current.getName() == first.getName()){selfPiece = 'B';}
    if(current.getName() == second.getName()){selfPiece = 'W';}

//
    loop = true;

    while(loop){
        //if(boardPositions[pos].getPiece())
    }
//                NE

//                E

//                SE

//                S

//                SW

//                W

//                NW
}
void Board::setPlayerOne(Player p)
{
    first = p;
}

void Board::setPlayerTwo(Player p)
{
    second = p;
}

void Board::setPlayerCurrent(Player p)
{
    current = p;
}

Player Board::getPlayerOne()
{
    return first;
}

Player Board::getPlayerTwo()
{
    return second;
}

Player Board::getPlayerCurrent()
{
    return current;
}
