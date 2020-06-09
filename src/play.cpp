#include "custom.h"
#include <string>
#include <fstream>
#include "Player.h"
#include "gameState.h"

// Function is run inside loop so updates every frame
void play(bool &init, gameState &gs, Player &player, sf::View &camera, cfg config)
{
    if(!init)
    {
        init = true;

        std::fstream loadSave;
        loadSave.open(gs.lp.levelName);
            if(loadSave.good())
            {

                // LOADING LEVEL
                load_save(gs);
                player.setPosition(gs.lp.levelStart);
            }
            else
            {
                return;
            }
    }


    //update player movement
    movement(player, gs.blocks, gs.lp.currentCheckpoint, config);

}
