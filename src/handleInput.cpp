#include "../include/Player.h"
#include "../include/gameState.h"
#include "../include/custom.h"
#include <SFML/Graphics.hpp>

void handleInput(sf::RenderWindow &app, sf::View camera, sf::Event event, std::shared_ptr<Player> &p, gameState *gs)
{

    switch (event.type) //check for mouse release. Otherwise we end up detecting 20 clicks and deleting everything!
    {
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if(gs->gamemode == Gamemode::creative)
                    create_block(app, camera, gs);
                break;
            }

            if (event.mouseButton.button == sf::Mouse::Right)
            {
                if(gs->gamemode == Gamemode::creative)
                    destroy_block(gs->blocks);
                break;
            }

            break;


        case sf::Event::KeyReleased:

            if(event.key.code == sf::Keyboard::F1)
            {
                gs->bp.isDeadly = !gs->bp.isDeadly;
                break;
            }

            if(event.key.code == sf::Keyboard::F2)
            {
                gs->bp.isStart = !gs->bp.isStart;
                break;
            }

            if(event.key.code == sf::Keyboard::F3)
            {
                gs->bp.isCheckpoint = !gs->bp.isCheckpoint;
                break;
            }

            if(event.key.code == sf::Keyboard::F4)
            {
                gs->bp.isFinish = !gs->bp.isFinish;
                break;
            }

             if(event.key.code == sf::Keyboard::F5)
            {
                gs->bp.isBreakable = !gs->bp.isBreakable;
                break;
            }

            if(event.key.code == sf::Keyboard::F6)
            {
                load_save(*gs);
                p->setPosition(gs->lp.currentCheckpoint);
            }

            if(event.key.code == sf::Keyboard::F7)
            {
                save_game(gs->blocks, gs->entities);
            }

            if(event.key.code == sf::Keyboard::F8)
            {
                gs->gamemode = Gamemode::playing;
            }

            if(event.key.code == sf::Keyboard::F9)
            {
                gs->gamemode = Gamemode::creative;
            }

            if(event.key.code == sf::Keyboard::E && gs->gamemode == Gamemode::creative)
            {
                gs->bp.textureIndex += 1;
                if (gs->bp.textureIndex > int(gs->textures->size() - 1))
                    gs->bp.textureIndex =  0;
            }

            if(event.key.code == sf::Keyboard::Q && gs->gamemode == Gamemode::creative)
            {
                gs->bp.textureIndex -= 1;
                if (gs->bp.textureIndex < 0)
                    gs->bp.textureIndex = gs->textures->size() - 1;
            }

            if(event.key.code == sf::Keyboard::S && event.key.shift && gs->gamemode == Gamemode::creative)
            {
                gs->creativeSettings.isPositionSnapping = !gs->creativeSettings.isPositionSnapping;
            }
            break;



    default:
        break;

    }


}
