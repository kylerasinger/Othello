#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position();
        virtual ~Position();
        bool canPlay();
        static const char EMPTY = ' ';
        static const char BLACK = 'B';
        static const char WHITE = 'W';

    protected:

    private:
        char piece;
};

#endif // POSITION_H
