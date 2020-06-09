#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include <SFML/Graphics/Sprite.hpp>

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
        block(blockProperties bp, sf::Texture &texture, sf::Vector2f position);
        virtual ~block();

    protected:
    private:
};


#endif // BLOCK_H_INCLUDED
