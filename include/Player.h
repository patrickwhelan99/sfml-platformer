#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Entity.h"
#include <vector>



class Player : public Entity
{

    private:






    public:
        Player();
        virtual ~Player();

        void doMovement(std::vector<block> &blocks, std::vector<Entity*> entities, cfg config, double deltaTime);
        void handleCollision(Entity* &collider, cfg &config){};


        void death();
        void handleInput();



    protected:



};

#endif // PLAYER_H
