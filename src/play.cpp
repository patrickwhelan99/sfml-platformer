#include "../include/custom.h"
#include <string>
#include <fstream>
#include "../include/Player.h"
#include "../include/gameState.h"

// Function is run inside loop so updates every frame
void play(gameState *gs, std::shared_ptr<Player> &player, sf::View &camera, cfg config, double deltaTime)
{
    player->handleInput();

    for(std::shared_ptr<Entity> &e : gs->entities)
    {
        e->doMovement(gs->blocks, gs->entities, config, deltaTime);

        if(e->getIsDead() && std::dynamic_pointer_cast<Player>(e))
        {
            e->setPosition(gs->lp.currentCheckpoint);
            e->setIsDead(false);
        }
    }

}
