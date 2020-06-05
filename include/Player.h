#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>


class Player : public sf::Sprite
{

    using Sprite::Sprite;


    public:
        Player();
        virtual ~Player();

        bool canJump = false;
        bool isFalling = false;

        sf::Clock fallingClock;

        sf::Vector2f getVelocity(){return this->velocity;};
        sf::Vector2f addVelocity(sf::Vector2f vel){this->velocity += vel;};
        sf::Vector2f setVelocity(sf::Vector2f vel){this->velocity = vel;};

    protected:

    private:
        sf::Vector2f velocity;

};

#endif // PLAYER_H
