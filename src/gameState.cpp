#include "gameState.h"

gameState::gameState(std::vector<sf::Texture> *t)
{
    this->textures = t;
}

gameState::~gameState()
{
    //dtor
}
