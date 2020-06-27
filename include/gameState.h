#ifndef GAMESTATE_H
#define GAMESTATE_H

class Entity;
class Player;

#include "block.h"
#include "Entity.h"
#include "Player.h"
#include <vector>
#include <string>

enum class Gamemode {menu, playing, creative};

class gameState
{


    struct creativeModeStruct
    {
        bool isPositionSnapping = false;
        float snappingSize = 50;
        int textureIndex = 1;
    };

    struct levelProperties
    {
        sf::Vector2f levelStart;
        sf::Vector2f currentCheckpoint;
        sf::Vector2f levelEnd;
        std::string levelName;
    };


public:
    std::shared_ptr<Player> player;
    blockProperties bp;
    levelProperties lp;
    creativeModeStruct creativeSettings;
    Gamemode gamemode = Gamemode::menu;
    std::vector<block> blocks;
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<sf::Texture>* textures;


    gameState(std::vector<sf::Texture> *t);
    virtual ~gameState();



protected:

private:
};

#endif // GAMESTATE_H
