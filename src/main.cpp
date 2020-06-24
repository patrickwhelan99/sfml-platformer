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


    texture_init(*gameState.textures);

    // Define player
    sf::Texture spriteTexture;
    spriteTexture.loadFromFile("textures/red_box.png");
    Player player;
    player.setTexture(spriteTexture);

    walker walk;
    walk.setTexture(gameState.textures->at(0));
    walk.scale(sf::Vector2f(0.25, 0.25));
    walk.currentDirection = Direction::right;

    gameState.player = &player;
    gameState.entities.push_back(&player);
    gameState.entities.push_back(&walk);

    // define camera
    sf::View camera = create_camera(player);
    update_view(app, camera, gameState.blocks, gameState.entities);



    int texturePos = 0;

    sf::Font font;
    font.loadFromFile("fonts/DroidSans.ttf");

    sf::Clock currentTime;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;

        double deltaTime = 3000 * currentTime.restart().asSeconds();



        block ghost(gameState.bp, gameState.textures->at(0), sf::Vector2f(0, 0));
        ghost.setOrigin(40, 40);


        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                app.close();
            }

            handleInput(app, camera, event, player, &gameState);

        }
        if(gameState.gamemode == Gamemode::playing)
        {

            printf("%f, %f\n", walk.getPosition().x, walk.getPosition().y);

            play(&gameState, player, camera, config, deltaTime);
            update_view(app, camera, gameState.blocks, gameState.entities);
        }

        if(gameState.gamemode == Gamemode::creative)
        {
            create(gameState, player, app, camera, ghost, font);
        }




    }

    return EXIT_SUCCESS;
}
