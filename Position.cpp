#include "Position.h"

Position::Position()
{
    //ctor
}

Position::~Position()
{
    //dtor
}

bool Position::canPlay()
{
    if(piece == '.')
    {
        return true;
    }else{
        return false;
    }

}

void Position::setPiece(char n)
{
    piece = n;
}

char Position::getPiece()
{
    return piece;
}
