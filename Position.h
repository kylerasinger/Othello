#ifndef POSITION_H
#define POSITION_H

//#include "Board.h"


class Position
{
    public:
        Position();
        virtual ~Position();
        virtual bool canPlay(int index);
        virtual bool canPlayOld();
        static const char EMPTY = '.';
        static const char BLACK = 'B';
        static const char WHITE = 'W';
        void setPiece(char n);
        char getPiece();

    protected:

    private:
        char piece;
};

#endif // POSITION_H
