#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>

#include "Entity.h"
#include <vector>



class Player : public Entity
{

    private:






    public:
        Player();
        virtual ~Player();

        void doMovement(std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> entities, cfg config, double deltaTime);
        void handleCollision(Entity* &collider, cfg &config){};


        void death();
        void handleInput();



    protected:



};


CEREAL_REGISTER_TYPE(Player);
CEREAL_REGISTER_POLYMORPHIC_RELATION(Entity, Player)

#endif // PLAYER_H
