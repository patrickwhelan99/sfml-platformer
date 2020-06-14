#include <SFML/Graphics.hpp>
#include "custom.h"

#ifndef UPDATE_VIEW_CPP_INCLUDED
#define UPDATE_VIEW_CPP_INCLUDED

void update_view(sf::RenderWindow &app, sf::View &camera, std::vector<block> &blocks, sf::Sprite &player)
{
    app.clear();

    camera.setCenter(player.getPosition().x, player.getPosition().y);
    app.setView(camera);

    for (auto const &block: blocks)
    {
        app.draw(block);
    }

    app.draw(player);

    app.display();

}


#endif // UPDATE_VIEW_CPP_INCLUDED
