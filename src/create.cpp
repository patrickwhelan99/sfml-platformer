#include "custom.h"

#include <string>


void create(gameState &gs, sf::Sprite &player, sf::RenderWindow &app, sf::View &camera, block &ghost, sf::Font &font)
{
    app.clear();

       /*   Text Instructions   */

    std::string helpString = "F1) Deadly: " + std::to_string(gs.bp.isDeadly) + "\n" + "F2) Spawn: " + std::to_string(gs.bp.isStart) + "\n" + "F3) Checkpoint: " + std::to_string(gs.bp.isCheckpoint) + "\n" + "F4) Finish: " + std::to_string(gs.bp.isFinish) + "\n" + "F5) Breakable: " + std::to_string(gs.bp.isBreakable) + "\nF6) Load Level\nF7) Save Level\nQ & E) Cycle through textures";

    // Create a text
    sf::Text text(helpString, font);
    text.setCharacterSize(10);





        /*   Ghost Block   */

    sf::Vector2i badMouse = {sf::Mouse::getPosition(app).x, sf::Mouse::getPosition(app).y};
    sf::Vector2f mouse = app.mapPixelToCoords(badMouse, camera); // Get coords for the special view (camera following character)


    if(gs.creativeSettings.isPositionSnapping)
        ghost.setPosition(getClosestSnappingPoint(mouse, &gs));
    else
        ghost.setPosition(mouse);


    ghost.setTexture(gs.textures->at(gs.bp.textureIndex));


    camera.setCenter(player.getPosition().x, player.getPosition().y);
    app.setView(camera);
    for (auto const &blocks: gs.blocks)
    {
        app.draw(blocks);
    }

    for(Entity* &e : gs.entities)
    {
        app.draw(*e);
    }

    app.draw(ghost);
    text.setPosition(app.mapPixelToCoords({0, 50}, camera));
    app.draw(text); // Draw text last so in foreground
    app.display();


    /*   MOVEMENT   */


    const float speed = 0.15;
    float x = 0;
    float y = 0;
    sf::Vector2f movementVector;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        x -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        x += speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        y -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        y += speed;
    }

    movementVector = {x, y};
    player.move(movementVector);
}
