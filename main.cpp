//Kyle Rasinger, 40247163
//March 8th 2023

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "Position.h"
#include "UnplayablePosition.h"

using namespace std;

int main()
{
    char menuSelection;
    cout << " -===- Othello -===- \n\n 1. Quit \n 2. Load a game \n 3. Start a new game. \n\n";
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
        }
        case '3':{ //Save a game

        }

    }


    return 0;
}
