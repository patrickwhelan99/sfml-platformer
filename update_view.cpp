#include <SFML/Graphics.hpp>
#include "custom.h"

#ifndef UPDATE_VIEW_CPP_INCLUDED
#define UPDATE_VIEW_CPP_INCLUDED

    using namespace std;

void update_view(sf::RenderWindow &app, sf::View &camera, vector<block> sprites, sf::Sprite player)
{
    app.clear();

    camera.setCenter(player.getPosition().x, player.getPosition().y);
    app.setView(camera);

    for (auto const &sprite: sprites)
    {
        app.draw(sprite);
    }

    app.draw(player);

    app.display();

}


#endif // UPDATE_VIEW_CPP_INCLUDED
