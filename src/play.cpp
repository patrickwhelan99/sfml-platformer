#include "custom.h"
#include <string>
#include <fstream>
#include "Player.h"

// Function is run inside loop so updates every frame
void play(bool &init, std::string levelName, std::vector<block> &sprites, std::vector<sf::Texture> &textures, sf::Vector2f &levelStart, sf::Vector2f &lastCheckpoint, sf::Vector2f &levelFinish, Player &player, sf::View &camera, cfg config)
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
    movement(player, sprites, lastCheckpoint, config);

}
