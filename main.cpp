//Kyle Rasinger, 40247163
//March 8th 2023

//left off fixing checkMove(int). crashes when on top line

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "Position.h"
#include "UnplayablePosition.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    char menuSelection;
    cout << " -===- OTHELLO -===- \n\n 1. Quit \n 2. Load a game \n 3. Start a new game. \n\n";
    cin >> menuSelection;
    while(menuSelection != '1' && menuSelection != '2' && menuSelection != '3'){
        cout << "That is not an option, try again: \n";
        cin >> menuSelection;
    }

    switch(menuSelection){
        case '1':{ //Quit
            cout << "Closing Program... ";
            return 0;
        }
        case '2':{ //Load a game
            Board first;
            first = first.load();

            Game newGame;
            newGame.setBoard(first);

            newGame.start();

            break;
        }
        case '3':{ //Start a new game
            cout << "Starting a new game... \n" ;
            string firstName;
            string secondName;
            int firstTurn; //1 for first, 2 for second.

            cout << "\nEnter player 1: ";
            cin >> firstName;

            do{
                cout << "Enter player 2: ";
                cin >> secondName;
            }
            while(firstName == secondName);

            Player firstPlayer(firstName);
            Player secondPlayer(secondName);
            //cout << "TEST OF NAME: " << firstPlayer.getName() << firstPlayer.getName() << firstPlayer.getName();


            Game newGame(firstPlayer, secondPlayer);
            //newGame.setBoard(newGame.getBoard());

            system("CLS");

            cout << "-===- CHOOSE BOARD -===- \n";
            //ask use which board?
            short startOption;
            cout << "Starting boards: \n\n";

            //print default boards
            //___can probably make this a method.

            string defaultBoardOne = "default_1.txt";
            ifstream boardFileOne(defaultBoardOne);
            ostringstream ss;

            string defaultBoardTwo = "default_2.txt";
            ifstream boardFileTwo(defaultBoardTwo);
            ostringstream ss2;

            int currentLine = 0;
            string line;
            ostringstream ssBoard;
            while(!boardFileOne.eof())
            {
                currentLine++;
                getline(boardFileOne, line);
                ssBoard << line;
                ssBoard << "\n";
            }

            currentLine = 0;
            string line2;
            ostringstream ssBoard2;
            while(!boardFileTwo.eof())
            {
                currentLine++;
                getline(boardFileTwo, line2);
                ssBoard2 << line2;
                ssBoard2 << "\n";
            }

            cout << "1. \n" << ssBoard.str() << "\n";
            cout << "2. \n" << ssBoard2.str();

            string boardOneString = ssBoard.str();
            string boardTwoString = ssBoard2.str();

            //removes '\n' from the strings, letting it be passed into setBoardPositions.
            boardOneString.erase(std::remove(boardOneString.begin(), boardOneString.end(), '\n'),
                    boardOneString.end());
            boardTwoString.erase(std::remove(boardTwoString.begin(), boardTwoString.end(), '\n'),
                    boardTwoString.end());

            //get input for default boards
            char input1 = '0';
            cout << "Default board selection: ";
            cin.clear();
            cin.ignore();
            cin >> input1;

            //set newGames board to the chosen default board.
            string boardString = "unitiliazed";
            if(input1 == '1')
            {
                boardString = boardOneString;
            }else if(input1 == '2')
            {
                boardString = boardTwoString;
            }

            system("CLS");

            Board theBoard;
            theBoard = newGame.getBoard();
            //cout << " MEGA TEST " << boardString;
            theBoard.setBoardPositions(boardString); //draws aswell
            newGame.setBoard(theBoard);

            newGame.start();


            break;
        }

    }


    return 0;
}
