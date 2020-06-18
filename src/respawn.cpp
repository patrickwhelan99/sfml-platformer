#include "../include/custom.h"

void respawn(sf::Sprite &player, sf::Vector2f lastCheckpoint) // STUB add respawn points
{
    if(lastCheckpoint.x != 0 && lastCheckpoint.y != 0)
        player.setPosition(lastCheckpoint);
    else
        player.setPosition(0, -100);
}
