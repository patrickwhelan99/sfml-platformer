#include "custom.h"

block::block()
{
    sf::Texture whiteBox;
    whiteBox.loadFromFile("./textures/white_box.png");

    this->setTexture(whiteBox);
}

block::~block()
{
    //dtor
}
