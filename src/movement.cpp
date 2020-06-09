#include "custom.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include <cmath>


void movement(Player &player, std::vector<block> &sprites, sf::Vector2f &lastCheckpoint, cfg config)
{
    const float speed = .2 * config.speed;
    const float gravity = .2 * config.gravity;
    const double maxHorizontalMovement = .1 * config.maxHorizontalMovement;
    const double maxVerticalMovement = .1 * config.maxVerticalMovement;
    const float terminalVelocity = 1 * config.terminalVelocity;
    const float terminalHorizontalVelocity = 1 * config.terminalHorizontalVelocity;


    sf::Vector2f previousPosition = player.getPosition();

    sf::Vector2f velocityChange;

    velocityChange += sf::Vector2f(0, gravity); // Gravity

    if(player.isFalling)
    {
        double t = player.fallingClock.getElapsedTime().asSeconds();
        double d = t*gravity;
        velocityChange += sf::Vector2f(0, d);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocityChange += sf::Vector2f(-speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.canJump)
        velocityChange += sf::Vector2f(0, -speed*1000);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocityChange += sf::Vector2f(speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        velocityChange += sf::Vector2f(0, speed);


    player.addVelocity(velocityChange);

    if(std::abs(player.getVelocity().x) > terminalHorizontalVelocity)
    {
        if(player.getVelocity().x < 0)
            player.setVelocity(sf::Vector2f(-terminalHorizontalVelocity, player.getVelocity().y));
        else
            player.setVelocity(sf::Vector2f(terminalHorizontalVelocity, player.getVelocity().y));
    }

    if(std::abs(player.getVelocity().y) > terminalVelocity)
    {
        if(player.getVelocity().y > 0)
            player.setVelocity(sf::Vector2f(player.getVelocity().x, terminalVelocity));

    }






    // Handle Horizontal movement
    if(std::abs(player.getVelocity().x) > maxHorizontalMovement)
    {
        if(player.getVelocity().x < 0)
        {
            player.move(-maxHorizontalMovement, 0);
            player.addVelocity(sf::Vector2f(maxHorizontalMovement, 0));
        }
        else
        {
            player.move(maxHorizontalMovement, 0);
            player.addVelocity(sf::Vector2f(-maxHorizontalMovement, 0));
        }
    }
    else
    {
        player.move(player.getVelocity().x, 0);
        player.addVelocity(sf::Vector2f(-player.getVelocity().x, 0));
    }


    bool hit = false;
    int counter = 0;
    for (auto const &sprite: sprites)
    {
        sf::FloatRect boxHitBox = sprite.getGlobalBounds();
        sf::FloatRect playerHitBox = player.getGlobalBounds();

        while (playerHitBox.intersects(boxHitBox))
        {
            hit = true;
            /*
            if(sprite.deadly == true)
                respawn(player, lastCheckpoint);

            if(sprite.breakable == true)
                sprites.erase(sprites.begin() + counter);

            if(sprite.savePoint)
            {
                sf::Vector2f temp = sprite.getPosition();
                temp.y -= 50;
                lastCheckpoint = temp;
            }
            */
            if(hit)
            {
                player.setPosition(previousPosition.x, player.getPosition().y);
                playerHitBox = player.getGlobalBounds();
                player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
            }
        }
    }




    // Handle Vertical movement
    if(std::abs(player.getVelocity().y) > maxVerticalMovement)
    {
        if(player.getVelocity().y < 0)
        {
            player.move(0, -maxVerticalMovement);
            player.addVelocity(sf::Vector2f(0, maxVerticalMovement));
        }
        else
        {
            player.move(0, maxVerticalMovement);
            player.addVelocity(sf::Vector2f(0, -maxVerticalMovement));
        }
    }
    else
    {
        player.move(0, player.getVelocity().y);
        player.addVelocity(sf::Vector2f(0, -player.getVelocity().y));
    }

    hit = false;
    counter = 0;
    for (block &sprite: sprites)
    {
        sf::FloatRect boxHitBox = sprite.getGlobalBounds();
        sf::FloatRect playerHitBox = player.getGlobalBounds();

        if(playerHitBox.intersects(boxHitBox))
        {
            hit = true;
            /*
            if(sprite.deadly == true)
                respawn(player, lastCheckpoint);

            if(sprite.breakable == true)
                sprites.erase(sprites.begin() + counter);

            if(sprite.savePoint)
            {
                sf::Vector2f temp = sprite.getPosition();
                temp.y -= 50;
                lastCheckpoint = temp;
            }
            */
            player.setPosition(player.getPosition().x, previousPosition.y);
            playerHitBox = player.getGlobalBounds();
            player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
            player.canJump = true;
            player.isFalling = false;
        }

        // Didn't hit anything on the vertical axis assume we are falling
        if(!hit && !player.isFalling)
        {
            player.isFalling = true;
            player.canJump = false;
            player.fallingClock.restart(); // Keep a falling clock so we can simulate acceleration over time till terminal velocity is reached
        }
    }
}
