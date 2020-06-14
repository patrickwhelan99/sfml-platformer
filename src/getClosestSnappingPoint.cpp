#include <SFML/Graphics/Transform.hpp>
#include <cmath>
#include "gameState.h"

sf::Vector2f getClosestSnappingPoint(sf::Vector2f currentPosition, gameState *gs)
{
    float gridSize = gs->creativeSettings.snappingSize;
    return sf::Vector2f(roundf(currentPosition.x/gridSize)*gridSize, roundf(currentPosition.y/gridSize)*gridSize);
}
