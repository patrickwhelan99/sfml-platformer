#ifndef WALKER_H
#define WALKER_H

#include <enemy.h>

enum class Direction {left, right};

class walker : public enemy
{
    public:
        walker();
        virtual ~walker();

        Direction currentDirection = Direction::right;


    protected:

    private:
};

#endif // WALKER_H
