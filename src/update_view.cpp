#include <SFML/Graphics.hpp>
#include "../include/custom.h"

#ifndef UPDATE_VIEW_CPP_INCLUDED
#define UPDATE_VIEW_CPP_INCLUDED

void update_view(sf::RenderWindow &app, sf::View &camera, std::vector<block> &blocks, std::vector<Entity*> &entities)
{
    app.clear();





    for (block &block: blocks)
    {
        app.draw(block);
    }

    camera.setCenter(entities.front()->getPosition().x, entities.front()->getPosition().y);
    app.setView(camera);

    for (Entity* &entity: entities)
    {
        app.draw(*entity);
    }

    app.display();

}


#endif // UPDATE_VIEW_CPP_INCLUDED
