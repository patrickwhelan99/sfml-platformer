#ifndef WALKER_H
#define WALKER_H

#include "enemy.h"

#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>


enum class Direction {left, right};

class walker : public enemy
{
    public:
        walker();
        virtual ~walker();

        void doMovement(std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> entities, cfg config, double deltaTime);
        void handleEntityCollision(std::shared_ptr<Entity> &collider);
        void handleBlockCollision(bool xAxis, block &collider);

        Direction currentDirection = Direction::right;



    protected:

    private:
};

CEREAL_REGISTER_TYPE(walker);
CEREAL_REGISTER_POLYMORPHIC_RELATION(Entity, walker)

#endif // WALKER_H
