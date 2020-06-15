#ifndef Entity_H
#define Entity_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

#include "block.h"
#include "cfg.h"


#include <vector>

class Entity : public sf::Sprite
{

    using Sprite::Sprite;

    private:
        sf::Vector2f velocity;
        bool isDead = false;





    public:
        Entity();
        virtual ~Entity();

        virtual void doMovement(std::vector<block> &blocks, std::vector<Entity*> entities, cfg config);
        virtual void handleCollision(Entity* &collider, cfg &config){};

        bool canJump = false;
        bool isFalling = false;

        sf::Clock fallingClock;

        sf::Vector2f getVelocity(){return this->velocity;};
        void addVelocity(sf::Vector2f vel){this->velocity += vel;};
        void setVelocity(sf::Vector2f vel){this->velocity = vel;};

        void setIsDead(bool dead){this->isDead = dead;};
        bool getIsDead(){return this->isDead;};


    protected:



};

#endif // Entity_H
