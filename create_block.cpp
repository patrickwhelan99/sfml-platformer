#include "custom.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

void create_block(sf::RenderWindow &app, std::vector<block> &sprites, sf::View &camera, bool deadly, bool start, bool checkpoint, bool finish, bool breakable, std::vector<sf::Texture> &textures, int &texturePos)
{

    sf::Vector2i mouse = {sf::Mouse::getPosition(app).x, sf::Mouse::getPosition(app).y};
    sf::Vector2f a = app.mapPixelToCoords(mouse, camera); // Get coords for the special view (camera following character)

        block newSprite;
        newSprite.setOrigin(40, 40);
        newSprite.setTexture(textures.at(texturePos));
        newSprite.texture = texturePos;

        newSprite.deadly = deadly;
        newSprite.startPoint = start;
        newSprite.savePoint = checkpoint;
        newSprite.finishPoint = finish;
        newSprite.breakable = breakable;

        newSprite.setPosition(a.x, a.y);
        sprites.push_back(newSprite);
        app.draw(newSprite);
        app.display();

}
