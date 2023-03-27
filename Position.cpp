#include "Position.h"
#include "Board.h"

Position::Position()
{
    //ctor
}

Position::~Position()
{
    //dtor
}

bool Position::canPlayOld()
{
    if(piece == EMPTY)
    {
        return true;
    }else{
        return false;
    }

}

bool Position::canPlay(int index)
{
    /*
    if(piece == EMPTY && Board::checkMove(index) == true)
    {
        return true;
    }else if(Board::checkMove(index) == false){
        return false;
    }*/
}

void Position::setPiece(char n)
{
    piece = n;
}

char Position::getPiece()
{
    return piece;
}
