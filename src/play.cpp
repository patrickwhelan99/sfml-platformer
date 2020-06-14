#include "custom.h"
#include <string>
#include <fstream>
#include "Player.h"
#include "gameState.h"

// Function is run inside loop so updates every frame
void play(gameState *gs, Player &player, sf::View &camera, cfg config)
{
    for(Entity* &e : gs->entities)
    {
        e->doMovement(gs->blocks, config);
    }

}
