#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

#include <iostream>

#include "custom.h"
#include "Player.h"
#include "gameState.h"


int main()
{
    cfg config = load_cfg();

    // Defining window
    sf::RenderWindow app(sf::VideoMode(config.xres, config.yres), "SFML window");
    app.setKeyRepeatEnabled(false);

    std::vector<sf::Texture> textures;
    gameState gameState(&textures);

    texture_init(*(gameState.textures));

    // Define player
    sf::Texture spriteTexture;
    spriteTexture.loadFromFile("textures/red_box.png");
    Player player;
    player.setTexture(spriteTexture);

    gameState.entities.push_back(&player);

    // define camera
    sf::View camera = create_camera(player);
    update_view(app, camera, gameState.blocks, player);



    int texturePos = 0;

    sf::Font font;
    font.loadFromFile("fonts/DroidSans.ttf");


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;


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
            play(&gameState, player, camera, config);
            update_view(app, camera, gameState.blocks, player);
        }

        if(gameState.gamemode == Gamemode::creative)
        {
            create(gameState, player, app, camera, ghost, font);
        }




    }

    return EXIT_SUCCESS;
}
