#include "../include/custom.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../include/block.h"
#include "../include/gameState.h"

void create_block(sf::RenderWindow &app, sf::View &camera, gameState *gs)
{

    sf::Vector2i badMouse = {sf::Mouse::getPosition(app).x, sf::Mouse::getPosition(app).y};
    sf::Vector2f mouse = app.mapPixelToCoords(badMouse, camera); // Get coords for the special view (camera following character)

    sf::Vector2f spawnPosition;

    if(gs->creativeSettings.isPositionSnapping)
        spawnPosition = getClosestSnappingPoint(mouse, gs);
    else
        spawnPosition = mouse;

    block newBlock(gs->bp, gs->textures->at(gs->bp.textureIndex), spawnPosition);
    gs->blocks.push_back(newBlock);
}
