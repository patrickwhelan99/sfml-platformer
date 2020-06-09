#include "custom.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "block.h"
#include "gameState.h"

void create_block(sf::RenderWindow &app, sf::View &camera, gameState *gs)
{

    sf::Vector2i mouse = {sf::Mouse::getPosition(app).x, sf::Mouse::getPosition(app).y};
    sf::Vector2f spawnPosition = app.mapPixelToCoords(mouse, camera); // Get coords for the special view (camera following character)

    block newBlock(gs->bp, gs->textures->at(gs->bp.textureIndex), spawnPosition);
    gs->blocks.push_back(newBlock);
}
