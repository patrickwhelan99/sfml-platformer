#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include <SFML/Graphics/Sprite.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/vector.hpp>

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
			archive( this->getPosition().x, this->getPosition().y, bp.isDeadly, bp.isCheckpoint, bp.isStart, bp.isFinish, bp.isBreakable, bp.textureIndex);
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
