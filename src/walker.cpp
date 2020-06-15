#include "walker.h"
#include "Player.h"

walker::walker()
{
    //ctor
}

walker::~walker()
{
    //dtor
}


void walker::doMovement(std::vector<block> &blocks, std::vector<Entity*> entities, cfg config)
{
    const float speed = .1 * config.speed;
    const float gravity = .2 * config.gravity;
    const double maxHorizontalMovement = .1 * config.maxHorizontalMovement;
    const double maxVerticalMovement = .1 * config.maxVerticalMovement;
    const float terminalVelocity = 1 * config.terminalVelocity;
    const float terminalHorizontalVelocity = 1 * config.terminalHorizontalVelocity;


    sf::Vector2f previousPosition = this->getPosition();

    sf::Vector2f velocityChange;

    velocityChange += sf::Vector2f(0, gravity); // Gravity

    if(this->isFalling)
    {
        double t = this->fallingClock.getElapsedTime().asSeconds();
        double d = t*gravity;
        velocityChange += sf::Vector2f(0, d);
    }

    if(this->currentDirection == Direction::left)
        velocityChange += sf::Vector2f(-(speed/2), 0);
    else
        velocityChange += sf::Vector2f((speed/2), 0);


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
        this->move(this->getVelocity().x, 0);
        this->addVelocity(sf::Vector2f(-this->getVelocity().x, 0));
    }


    bool hit = false;
    int counter = 0;
    for (auto const &block: blocks)
    {
        sf::FloatRect boxHitBox = block.getGlobalBounds();
        sf::FloatRect entityHitBox = this->getGlobalBounds();

        while (entityHitBox.intersects(boxHitBox))
        {
            this->setPosition(previousPosition.x, this->getPosition().y);
            entityHitBox = this->getGlobalBounds();
            this->setVelocity(sf::Vector2f(0, this->getVelocity().y));
            if(this->currentDirection == Direction::left)
                this->currentDirection = Direction::right;
            else
                this->currentDirection = Direction::left;
        }
    }






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
        this->move(0, this->getVelocity().y);
        this->addVelocity(sf::Vector2f(0, -this->getVelocity().y));
    }

    hit = false;
    counter = 0;
    for (block &block: blocks)
    {
        sf::FloatRect boxHitBox = block.getGlobalBounds();
        sf::FloatRect entityHitBox = this->getGlobalBounds();

        if(entityHitBox.intersects(boxHitBox))
        {
            hit = true;
            /*
            if(block.deadly == true)
                respawn(player, lastCheckpoint);

            if(block.breakable == true)
                blocks.erase(blocks.begin() + counter);

            if(block.savePoint)
            {
                sf::Vector2f temp = block.getPosition();
                temp.y -= 50;
                lastCheckpoint = temp;
            }
            */
            this->setPosition(this->getPosition().x, previousPosition.y);
            entityHitBox = this->getGlobalBounds();
            this->setVelocity(sf::Vector2f(this->getVelocity().x, 0));
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

    for(Entity* &e : entities)
    {
        sf::FloatRect entityHitBox = e->getGlobalBounds();
        sf::FloatRect thisHitBox = this->getGlobalBounds();

        if(thisHitBox.intersects(entityHitBox))
        {
            this->handleCollision(e, config);
        }
    }
}

void walker::handleCollision(Entity* &collider, cfg &config)
{
    if(dynamic_cast<Player*>(collider))
    {
        dynamic_cast<Player*>(collider)->death();
    }
}
