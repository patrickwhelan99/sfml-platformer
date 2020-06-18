#ifndef WALKER_H
#define WALKER_H

#include "enemy.h"

enum class Direction {left, right};

class walker : public enemy
{
    public:
        walker();
        virtual ~walker();

        void doMovement(std::vector<block> &blocks, std::vector<Entity*> entities, cfg config);
        void handleCollision(Entity* &collider, cfg &config);

        Direction currentDirection = Direction::right;


    protected:

    private:
};

#endif // WALKER_H
