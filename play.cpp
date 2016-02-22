#include "custom.h"
#include <string>
#include <fstream>

// Function is run inside loop so updates every frame
void play(bool &init, std::string levelName, std::vector<block> &sprites, std::vector<sf::Texture> &textures, sf::Vector2f &levelStart, sf::Vector2f &lastCheckpoint, sf::Vector2f &levelFinish, sf::Sprite &player, sf::View &camera, float &jumpSpeed)
{
    if(!init)
    {
        init = true;

        std::fstream loadSave;
        loadSave.open(levelName);
            if(loadSave.good())
            {

                // LOADING LEVEL
                load_save(sprites, textures, levelStart, levelFinish);
                player.setPosition(levelStart);
                lastCheckpoint = levelStart;
            }
            else
            {
                return;
            }
    }

    //update player movement
    sf::Vector2f playerVector = movement(player, sprites, playerVector, jumpSpeed, lastCheckpoint);
    player.move(playerVector);

}
