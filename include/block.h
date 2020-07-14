#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include <SFML/Graphics/Sprite.hpp>
#include "../include/cereal/archives/xml.hpp"
#include "../include/cereal/types/vector.hpp"

struct blockProperties
    {
        bool isDeadly = false;
        bool isCheckpoint = false;
        bool isStart = false;
        bool isFinish = false;
        bool isBreakable = false;
        int textureIndex = 0;
    };

class block : public sf::Sprite
{
    public:
        blockProperties bp;
        block(){};
        block(blockProperties bp, sf::Texture &texture, sf::Vector2f position);
        virtual ~block();


        template<class Archive>
		void save(Archive & archive) const
		{
			archive( cereal::make_nvp("x", this->getPosition().x), cereal::make_nvp("y", this->getPosition().y), cereal::make_nvp("deadly", bp.isDeadly), cereal::make_nvp("checkpoint", bp.isCheckpoint), cereal::make_nvp("start", bp.isStart), cereal::make_nvp("finish", bp.isFinish), cereal::make_nvp("breakable", bp.isBreakable), cereal::make_nvp("texture", bp.textureIndex));
		}

		template<class Archive>
		void load(Archive & archive)
		{
            float x, y;
			archive( x, y, bp.isDeadly, bp.isCheckpoint, bp.isStart, bp.isFinish, bp.isBreakable, bp.textureIndex);
			this->setPosition(sf::Vector2f(x, y));
		}

    protected:
    private:
};


#endif // BLOCK_H_INCLUDED
