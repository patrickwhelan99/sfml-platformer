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

        virtual void doMovement(std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> entities, cfg config, double deltaTime);
        virtual void handleCollision(bool xAxis, sf::Vector2f previousPosition, std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> &entities, cfg &config);
        virtual void handleEntityCollision(std::shared_ptr<Entity> &collider);
        virtual void handleBlockCollision(bool xAxis, block &collider);

        int textureIndex = 0;

        bool canJump = false;
        bool isFalling = false;

        sf::Clock fallingClock;

        sf::Vector2f getVelocity(){return this->velocity;};
        void addVelocity(sf::Vector2f vel){this->velocity += vel;};
        void setVelocity(sf::Vector2f vel){this->velocity = vel;};

        void setIsDead(bool dead){this->isDead = dead;};
        bool getIsDead(){return this->isDead;};


        template<class Archive>
		void save(Archive & archive) const
		{
			archive( cereal::make_nvp("x", this->getPosition().x), cereal::make_nvp("y", this->getPosition().y), cereal::make_nvp("texture", textureIndex));
		}

		template<class Archive>
		void load(Archive & archive)
		{
            float x, y;
			archive( x, y, textureIndex);
			this->setPosition(sf::Vector2f(x, y));
		}


    protected:



};

#endif // Entity_H
