#include "../include/walker.h"
#include "../include/Player.h"

walker::walker()
{
    //ctor
}

walker::~walker()
{
    //dtor
}

void walker::doMovement(std::vector<block> &blocks, std::vector<Entity*> entities, cfg config, double deltaTime)
{
    if(this->currentDirection == Direction::left)
        this->addVelocity(sf::Vector2f(-25, 0));
    else
        this->addVelocity(sf::Vector2f(25, 0));

    Entity::doMovement(blocks, entities, config, deltaTime);
}

void walker::handleEntityCollision(Entity* &collider)
{
    if(dynamic_cast<Player*>(collider))
    {
        dynamic_cast<Player*>(collider)->death();
    }
}

void walker::handleBlockCollision(bool xAxis, block &collider)
{
    if(!xAxis)
        return;

    if(this->currentDirection == Direction::left)
        this->currentDirection = Direction::right;
    else
        this->currentDirection = Direction::left;

}
