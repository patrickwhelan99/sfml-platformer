#include "custom.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2f movement(sf::Sprite &player, std::vector<block> &sprites, sf::Vector2f playerVector, float &vertSpeed, sf::Vector2f &lastCheckpoint)
{
        const float speed = 0.15;
        const float gravity = 0.05;
        bool canJump = false;
        float x = playerVector.x - playerVector.x / 2;
        float y = playerVector.y - playerVector.y / 2;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            x -= speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x += speed;
        }

        // check if proposed x movement will cause collision
        player.move(x, 0);
        sf::FloatRect playerHitBox = player.getGlobalBounds();

        bool hit = false;
        int counter = 0;
        for (auto const &sprite: sprites)
        {
            counter ++;
            sf::FloatRect boxHitBox = sprite.getGlobalBounds();

            if (playerHitBox.intersects(boxHitBox))
            {
                hit = true;
                if(sprite.deadly == true)
                    respawn(player, lastCheckpoint);

                if(sprite.breakable == true)
                    sprites.erase(sprites.begin() + counter);
            }

            if(hit)
            {
                if(sprite.savePoint)
                {
                    sf::Vector2f temp = sprite.getPosition();
                    temp.y -= 50;
                    lastCheckpoint = temp;
                }
            }
        }

        if (hit)
        {
            player.move(-x, 0);
            x = -x;
            //std::cout << "X collision" << std::endl;
        }

        player.move(-x, 0);

/********************************************************************************/
/**                           X - Stuff                                        **/
/**                                                                            **/
/**                           Y - Stuff                                        **/
/********************************************************************************/


        // check if proposed y movement will cause collision
        y += gravity;
        player.move(0, y);




        playerHitBox = player.getGlobalBounds();

        hit = false;
        counter = 0;
        for (auto const &sprite: sprites)
        {
            counter ++;
            sf::FloatRect boxHitBox = sprite.getGlobalBounds();

            if (playerHitBox.intersects(boxHitBox))
            {
                hit = true;
                    if(sprite.deadly == true)
                    respawn(player, lastCheckpoint);

                    if(sprite.breakable == true)
                        sprites.erase(sprites.begin() + counter);
            }

        }
        
        // Add check if touching ground
        if (hit)
        {
            player.move(0, -y);
            y = -y;
            canJump = true;
            //std::cout << "Y collision" << std::endl;
        }

        player.move(0, y);

        if (canJump)
        {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                   vertSpeed = speed*1.5; // set initial velocity for the jump
                }
            y -= gravity;
        }

        if (vertSpeed > 0)
        {
            y -= vertSpeed;
            vertSpeed = vertSpeed / 1.001; // smaller the division the more 'steps' in the jump (smoother)
        }
        else
        {
            vertSpeed = 0;
        }
/*
        // y += gravity;
        // player.move(0, y);
        playerHitBox = player.getGlobalBounds();

        hit = false;
        counter = 0;
        for (auto const &sprite: sprites)
        {
            counter ++;
            sf::FloatRect boxHitBox = sprite.getGlobalBounds();

            if (playerHitBox.intersects(boxHitBox))
            {
                hit = true;
                    if(sprite.deadly == true)
                    respawn(player, lastCheckpoint);

                    if(sprite.breakable == true)
                        sprites.erase(sprites.begin() + counter);
            }

        }

        if (hit)
        {
            player.move(0, -y);
            y = -y;
            canJump = true;
        }

        player.move(0, -y);

*/

    playerVector = {x, y};

 return playerVector;
}
