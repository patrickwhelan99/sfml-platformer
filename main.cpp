#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

#include <iostream>

#include "custom.h"



int main()
{
    // Defining window
    sf::RenderWindow app(sf::VideoMode(1920, 1080), "SFML window");
    app.setKeyRepeatEnabled(false);

    //define textures
    std::vector<sf::Texture> textures;
    /*
    sf::Texture redBox = texture_init(textures, "red_box.png");
    sf::Texture whiteBox = texture_init(textures, "white_box.png");
    sf::Texture blueBox = texture_init(textures, "blue_box.png");
    */
    texture_init(textures);

    // Define player
    sf::Texture spriteTexture;
    spriteTexture.loadFromFile("./textures/red_box.png");
    sf::Sprite player(spriteTexture);
    float jumpSpeed = 0;

    // vector containing all block sprites
    std::vector<block> sprites;

    // define camera
    sf::View camera = create_camera(player);
    update_view(app, camera, sprites, player);


    sf::Vector2f levelStart;
    sf::Vector2f levelFinish;
    sf::Vector2f lastCheckpoint;

    bool deadly = false; // toggleable for placing deadly blocks
    bool start;
    bool checkpoint;
    bool finish;
    bool breakable;

    bool modePlay = false;
    bool init = false; // check if level loaded in getplay
    bool modeCreate = false;

    int texturePos = 0;

    sf::Font font;
    font.loadFromFile("DroidSans.ttf");


    initialize(player, camera, sprites);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;


        bool leftMouseClicked = false;
        bool rightMouseClicked = false;
        bool saveGame = false;
        bool loadSave = false;


        block ghost;
        ghost.setOrigin(40, 40);


        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                app.close();
            }

            switch (event.type) //check for mouse release. Otherwise we end up detecting 20 clicks and deleting everything!
            {
                case sf::Event::MouseButtonReleased:
                     if (event.mouseButton.button == sf::Mouse::Left)
                     {
                        leftMouseClicked = true;
                        break;
                     }
                     if (event.mouseButton.button == sf::Mouse::Right)
                     {
                        rightMouseClicked = true;
                        break;
                     }
                    break;

                case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::F1)
                        {
                            if(!deadly)
                                deadly = true;
                            else
                                deadly = false;
                            break;
                        }

                        if(event.key.code == sf::Keyboard::F2)
                        {
                            if(!start)
                                start = true;
                            else
                                start = false;
                            break;
                        }

                        if(event.key.code == sf::Keyboard::F3)
                        {
                            if(!checkpoint)
                                checkpoint = true;
                            else
                                checkpoint = false;
                            break;
                        }

                        if(event.key.code == sf::Keyboard::F4)
                        {
                            if(!finish)
                                finish = true;
                            else
                                finish = false;
                            break;
                        }

                        if(event.key.code == sf::Keyboard::F5)
                        {
                            if(!breakable)
                                breakable = true;
                            else
                                breakable = false;
                            break;
                        }

                        if(event.key.code == sf::Keyboard::F6)
                            loadSave = true;

                        if(event.key.code == sf::Keyboard::F7)
                            saveGame = true;

                        if(event.key.code == sf::Keyboard::F8)
                        {
                            modeCreate = false;
                            modePlay = true;
                        }

                        if(event.key.code == sf::Keyboard::F9)
                        {
                            modePlay = false;
                            modeCreate = true;
                        }

                        if(event.key.code == sf::Keyboard::E && modeCreate)
                        {
                            texturePos += 1;
                                if (texturePos > textures.size() - 1)
                                    texturePos =  0;
                        }

                        if(event.key.code == sf::Keyboard::Q && modeCreate)
                        {
                            texturePos -= 1;
                                if (texturePos < 0)
                                    texturePos = textures.size() - 1;
                        }
                        break;

                default:
                    break;

            }

        }

        if(leftMouseClicked && modeCreate)
            create_block(app, sprites, camera, deadly, start, checkpoint, finish, breakable, textures, texturePos);

        if(rightMouseClicked && modeCreate)
            destroy_block(sprites);

        if(saveGame && modeCreate)
            save_game(sprites);

        if(loadSave)
        {
            std::vector<block> newVector;
            load_save(newVector, textures, levelStart, levelFinish);
            sprites = newVector;
            player.setPosition(levelStart);
        }

        sf::Sprite backGround;

        if(modePlay)
        {
            play(init, "savegame", sprites, textures, levelStart, lastCheckpoint, levelFinish, player, camera, jumpSpeed); // ADD SMOOTH EXIT FROM LEVELS AND RESET INIT BOOL
            update_view(app, camera, sprites, player);
        }

        if(modeCreate)
        {
            create(sprites, textures, player, app, camera, ghost, texturePos, font, deadly, start, checkpoint, finish, breakable);
        }




    }

    return EXIT_SUCCESS;
}
