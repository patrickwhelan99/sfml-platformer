#include "../include/custom.h"

block::block(blockProperties bp, sf::Texture &texture, sf::Vector2f position)
{
    this->setOrigin(40, 40);
    this->setTexture(texture);
    this->bp = bp;
    this->setPosition(position);
}

block::~block()
{
    //dtor
}
