#include "custom.h"
#include <string>
#include <fstream>
#include "Player.h"
#include "gameState.h"

// Function is run inside loop so updates every frame
void play(gameState &gs, Player &player, sf::View &camera, cfg config)
{
    //update player movement
    movement(player, gs.blocks, gs.lp.currentCheckpoint, config);

}
