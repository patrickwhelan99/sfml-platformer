#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <vector>
#include <fstream>
#include <iostream>

#include "../include/custom.h"
#include "../include/Player.h"
#include "../include/walker.h"
#include "../include/gameState.h"


int main()
{
    cfg config = load_cfg();

    // Defining window
    sf::RenderWindow app(sf::VideoMode(config.xres, config.yres), "SFML window");
    app.setKeyRepeatEnabled(false);

    std::vector<sf::Texture> textures;
    gameState gameState(&textures);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("textures/red_box.png");

    textures.push_back(playerTexture);


    texture_init(*gameState.textures);





    std::shared_ptr<walker> walk = std::make_shared<walker>();
    walk->setTexture(gameState.textures->at(0));
    walk->scale(sf::Vector2f(0.25, 0.25));
    walk->currentDirection = Direction::right;

    gameState.player = std::make_shared<Player>();
    gameState.player->setTexture(gameState.textures->at(0));

    gameState.entities.push_back(gameState.player);
    gameState.entities.push_back(walk);

    // define camera
    sf::View camera = create_camera(*gameState.player);
    update_view(app, camera, gameState.blocks, gameState.entities);


    sf::Font font;
    font.loadFromFile("fonts/DroidSans.ttf");

    sf::Clock currentTime;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;

        double deltaTime = 3000 * currentTime.restart().asSeconds();



        block ghost(gameState.bp, gameState.textures->at(1), sf::Vector2f(0, 0));
        ghost.setOrigin(40, 40);


        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                app.close();
            }

            handleInput(app, camera, event, gameState.player, &gameState);

        }
        if(gameState.gamemode == Gamemode::playing)
        {
            play(&gameState, gameState.player, camera, config, deltaTime);
            update_view(app, camera, gameState.blocks, gameState.entities);
        }

        if(gameState.gamemode == Gamemode::creative)
        {
            create(gameState, gameState.player, app, camera, ghost, font);
        }




    }

    return EXIT_SUCCESS;
}
