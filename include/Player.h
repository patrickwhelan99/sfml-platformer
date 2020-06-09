#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>



class Player : public sf::Sprite
{

    using Sprite::Sprite;

    private:
        sf::Vector2f velocity;





    public:
        Player();
        virtual ~Player();

        bool canJump = false;
        bool isFalling = false;

        sf::Clock fallingClock;

        sf::Vector2f getVelocity(){return this->velocity;};
        void addVelocity(sf::Vector2f vel){this->velocity += vel;};
        void setVelocity(sf::Vector2f vel){this->velocity = vel;};


    protected:



};

#endif // PLAYER_H
