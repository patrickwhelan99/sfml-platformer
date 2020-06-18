#include <SFML/Graphics.hpp>
#ifndef CAMERA_CPP_INCLUDED
#define CAMERA_CPP_INCLUDED

#include "../include/custom.h"

sf::View create_camera(sf::Sprite player)
{

    sf::View camera;
    camera.setCenter(sf::Vector2f(player.getPosition()));
    camera.setSize(1600, 900);

return camera;
}

#endif // CAMERA_CPP_INCLUDED
