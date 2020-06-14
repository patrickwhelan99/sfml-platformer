#include <SFML/Graphics.hpp>
#include "custom.h"

#ifndef UPDATE_VIEW_CPP_INCLUDED
#define UPDATE_VIEW_CPP_INCLUDED

void update_view(sf::RenderWindow &app, sf::View &camera, std::vector<block> &blocks, std::vector<Entity*> &entities)
{
    app.clear();





    for (block &block: blocks)
    {
        app.draw(block);
    }

    for (Entity* &entity: entities)
    {
        app.draw(*entity);
        printf("%f, %f\n", entity->getPosition().x, entity->getPosition().y);

        if(entity->acceptsInput)
        {
            camera.setCenter(entity->getPosition().x, entity->getPosition().y);
            app.setView(camera);
        }
    }

    app.display();

}


#endif // UPDATE_VIEW_CPP_INCLUDED
