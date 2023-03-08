#ifndef UNPLAYABLEPOSITION_H
#define UNPLAYABLEPOSITION_H

#include "Position.h"


class UnplayablePosition : public Position
{
    public:
        UnplayablePosition();
        virtual ~UnplayablePosition();
        static const char UNPLAYABLE = '*';

    protected:

    private:
};

#endif // UNPLAYABLEPOSITION_H
