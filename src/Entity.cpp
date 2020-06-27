#include "../include/Entity.h"

#include "../include/custom.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include <cmath>

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::doMovement(std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> entities, cfg config, double deltaTime)
{
    const float speed = .2 * config.speed * deltaTime;
    const float gravity = .2 * config.gravity * deltaTime;
    const double maxHorizontalMovement = .1 * config.maxHorizontalMovement * deltaTime;
    const double maxVerticalMovement = .1 * config.maxVerticalMovement * deltaTime;
    const float terminalVelocity = 1 * config.terminalVelocity * deltaTime;
    const float terminalHorizontalVelocity = 1 * config.terminalHorizontalVelocity * deltaTime;


    sf::Vector2f previousPosition = this->getPosition();

    sf::Vector2f velocityChange;

    velocityChange += sf::Vector2f(0, gravity); // Gravity

    if(this->isFalling)
    {
        double t = this->fallingClock.getElapsedTime().asSeconds();
        double d = t*gravity;
        velocityChange += sf::Vector2f(0, d);
    }

    this->addVelocity(velocityChange);

    if(std::abs(this->getVelocity().x) > terminalHorizontalVelocity)
    {
        if(this->getVelocity().x < 0)
            this->setVelocity(sf::Vector2f(-terminalHorizontalVelocity, this->getVelocity().y));
        else
            this->setVelocity(sf::Vector2f(terminalHorizontalVelocity, this->getVelocity().y));
    }

    if(std::abs(this->getVelocity().y) > terminalVelocity)
    {
        if(this->getVelocity().y > 0)
            this->setVelocity(sf::Vector2f(this->getVelocity().x, terminalVelocity));

    }






    // Handle Horizontal movement
    if(std::abs(this->getVelocity().x) > maxHorizontalMovement)
    {
        if(this->getVelocity().x < 0)
        {
            this->move(-maxHorizontalMovement, 0);
            this->addVelocity(sf::Vector2f(maxHorizontalMovement, 0));
        }
        else
        {
            this->move(maxHorizontalMovement, 0);
            this->addVelocity(sf::Vector2f(-maxHorizontalMovement, 0));
        }
    }
    else
    {
        this->move(this->getVelocity().x*deltaTime, 0);
        this->addVelocity(sf::Vector2f(-this->getVelocity().x, 0));
    }


    this->handleCollision(true, previousPosition, blocks, entities, config);



    // Handle Vertical movement
    if(std::abs(this->getVelocity().y) > maxVerticalMovement)
    {
        if(this->getVelocity().y < 0)
        {
            this->move(0, -maxVerticalMovement);
            this->addVelocity(sf::Vector2f(0, maxVerticalMovement));
        }
        else
        {
            this->move(0, maxVerticalMovement);
            this->addVelocity(sf::Vector2f(0, -maxVerticalMovement));
        }
    }
    else
    {
        this->move(0, this->getVelocity().y*deltaTime);
        this->addVelocity(sf::Vector2f(0, -this->getVelocity().y));
    }

    this->handleCollision(false, previousPosition, blocks, entities, config);


}

void Entity::handleCollision(bool xAxis, sf::Vector2f previousPosition, std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> &entities, cfg &config)
{
    bool hit = false;
    for (block &block: blocks)
    {
        sf::FloatRect boxHitBox = block.getGlobalBounds();
        sf::FloatRect thisHitBox = this->getGlobalBounds();

        if(thisHitBox.intersects(boxHitBox))
        {
            this->handleBlockCollision(xAxis, block);
            hit = true;


            if(xAxis)
                this->setPosition(previousPosition.x, this->getPosition().y);
            else
                this->setPosition(this->getPosition().x, previousPosition.y);

            this->canJump = true;
            this->isFalling = false;
        }

        // Didn't hit anything on the vertical axis assume we are falling
        if(!hit && !this->isFalling)
        {
            this->isFalling = true;
            this->canJump = false;
            this->fallingClock.restart(); // Keep a falling clock so we can simulate acceleration over time till terminal velocity is reached
        }
    }

    for(std::shared_ptr<Entity> &e : entities)
    {
        sf::FloatRect entityHitBox = e->getGlobalBounds();
        sf::FloatRect thisHitBox = this->getGlobalBounds();

        if(thisHitBox.intersects(entityHitBox))
        {
            handleEntityCollision(e);
        }

    }


}

void Entity::handleBlockCollision(bool xAxis, block &collider)
{

}

void Entity::handleEntityCollision(std::shared_ptr<Entity> &collider)
{

}

